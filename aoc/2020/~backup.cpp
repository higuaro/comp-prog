

rule_map_t to_cnf(rule_map_t& cfg, terminal_map_t& terminals) {
  int max_id = -1;
  queue<int> to_fix;
  for (auto& [rule_id, rule] : cfg) {
    for (auto& r : rule)
      if (r.size() != 2)
        to_fix.push(rule_id);
    max_id = max(max_id, rule_id);
  }
  rule_map_t cnf;

  for (auto [_, rule_id] : terminals)
    max_id = max(max_id, rule_id);

  set<int> empty_rules;
  while (!to_fix.empty()) {
    int rule_id = to_fix.front(); to_fix.pop();
    const auto& prod_rule = cfg[rule_id];

    // Empty rule
    if (!prod_rule.size()) {
      clog << "Found empty rule: " << rule_id << endl;
      empty_rules.insert(rule_id);
    }

    int alternatives = prod_rule.size();
    for (int ri = alternatives - 1; ri >= 0; ri--) {
      auto& alternative = prod_rule[ri];
      int n = alternative.size();
      //clog << " > rule #" << rule_id << '_' << ri << ".size=" << n << endl;

      if (n == 1) {
        int target = sub_rule[0];
        for (auto& [_, rule] : rules)
          for (auto& sub_r : rule)
            for (int i = 0; i < static_cast<int>(sub_r.size()); i++)
              if (sub_r[i] == rule_id)
                sub_r[i] = target;
        rule.erase(begin(rule) + ri);
      } else if (n > 2) {
        for (int k = n - 1; k >= 2; k--) {
          rules[++max_id] = {{sub_rule[k - 1], sub_rule[k]}};
          sub_rule.pop_back();
          sub_rule.pop_back();
          sub_rule.push_back(max_id);
        }
      }
    }

    for (auto& [rule_id, rule] : rules)
      for (auto& r : rule)
        if (r.size() != 2)
          q.push(rule_id);
  }

  return cnf;
}
void print_rules(rule_map_t& rules, terminal_map_t& terms) {
  vector<int> ids;
  for (auto& [id, _] : rules)
    ids.push_back(id);
  sort(begin(ids), end(ids));
  for (int id : ids) {
    auto& rule = rules[id];
    bool first = true;
    cout << id << ": ";
    for (auto& sub_rule : rule) {
      if (!first) cout << " | ";
      for (auto target : sub_rule) 
        cout << target << ' ';
      first = false;
    }
    cout << endl;
  }
  for (auto [t, rule_id] : terms)
    cout << rule_id << ": " << t << endl;
}
void print_cyk(cyk_t& t) {
  int n = t.size();
  int m = t[0].size();
  int r = t[0][0].size();
  cerr << "<table border=1>" << endl;
  cerr << "<tr>" << endl;
  for (int j = 0; j < m; j++)
    cerr << "<td>" << j << "</td>";
  cerr << "</tr>" << endl;

  for (int i = 0; i < n; i++) {
    cerr << "<tr>" << endl;
    for (int j = 0; j < m - i; j++) {
      cerr << "<td> ";
      for (int k = 0; k < r; k++)
        if (t[i][j][k])
          cerr << k << ' ';
      cerr << "</td>";
    }
    cerr << "\n</tr>" << endl;
  }
  cerr << "</table>" << endl;
}
