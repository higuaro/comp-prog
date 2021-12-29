#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<vector<char>>> cyk_t;
typedef unordered_map<int, vector<vector<int>>> rule_map_t;
typedef unordered_map<char, int> terminal_map_t;

// Assumes rules are already converted to CNF
//
// Either a rule or a terminal
variant<vector<vector<int>>, char> parse_rule(const string& r) {
  istringstream iss(r);
  string token;
  vector<vector<int>> rules;
  vector<int> current;
  while (iss >> token) {
    if (token[0] == '"')
      return token[1];
    if (token == "|") {
      rules.push_back(current);
      current = {};
    } else
      current.push_back(stoi(token));
  }
  if (!current.empty())
    rules.push_back(current);
  return rules;
}

cyk_t cyk(rule_map_t& rules, terminal_map_t& terminals, const string& word) {
  int n = word.size();
  int r = rules.size() + terminals.size();
  cyk_t t(n, vector<vector<char>>(n, vector<char>(r, 0)));
  for (int i = 0; i < n; i++)
    t[0][i][terminals[word[i]]] = true;
  for (int l = 1; l < n; l++) { // 0-based 'length' index
    for (int w = 0; w < n - l; w++) { // window start pos
      for (int s = l - 1; s >= 0; s--) {

        int row_i = s;
        int col_i = w;

        int row_j = l - 1 - s;
        int col_j = w + s + 1;

        for (auto& [rule_id, rule] : rules) {
          if (!rule.size()) {
            cerr << rule_id << " |rules| == 0: " << endl;
            exit(1);
          }
          for (auto& r_i : rule) {
            if (r_i.size() != 2) {
              cerr << rule_id << " |r_i| != 2: " << r_i.size() << endl;
              exit(1);
            }
            // r_i = rule_id -> bc
            int b = r_i[0];
            int c = r_i[1];

            if (t[row_i][col_i][b] && t[row_j][col_j][c]) {
              t[l][w][rule_id] = 1;
              break;
            }
          }
        }
      }
    }
  }
  return t;
}

int main() {
  string line;
  rule_map_t prod_rules;
  terminal_map_t terminals;
  while (getline(cin, line, '\n')) {
    if (line.empty()) break;
    int colon = line.find(':');
    int rule_id = stoi(line.substr(0, colon));
    auto rule = parse_rule(line.substr(colon + 1));
    if (rule.index()) {
      char terminal = get<1>(rule);
      terminals[terminal] = rule_id;
    } else {
      prod_rules[rule_id] = get<0>(rule);
    }
  }

  int total = 0;
  int line_index = 0;
  while (getline(cin, line, '\n')) {
    //cerr << line << endl;
    //cerr << prod_rules.size() << ',' << terminals.size() << endl;
    cyk_t t = cyk(prod_rules, terminals, line);
    //print_cky(t);
    if (t[line.size() - 1][0][0]) {
      cerr << "[match] line: " << line_index << '=' << line << " - "
        << t[line.size() - 1][0][0] << endl;
      total++;
    }
    line_index++;
  }
  cout << total << endl;
  return 0;
}
