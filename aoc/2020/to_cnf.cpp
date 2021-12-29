#include <bits/stdc++.h>
using namespace std;
typedef variant<vector<vector<int>>, char> rule_t;

rule_t parse_rule(const string& l) {
  if (l[0] == '"') return l[1]; // terminal

  vector<vector<int>> rule;
  istringstream iss(l);
  string token;
  vector<int> alternative;
  while (getline(iss, token, ' ')) {
    if (token == "|") {
      rule.push_back(alternative);
      alternative = {};
    }
    alternative.push_back(stoi(token));
  }
  if (alternative.size()) rule.push_back(alternative);
  return rule;
}

int main() {
  unordered_map<int, rule_t> rules;
  string line;
  int max_id = 0;
  while (getline(cin, line, '\n')) {
    int colon_index = line.find(':');
    // the `+ 1` is to shifts ids by 1, this way we can add
    // a new rule 0 (S0) for step 1
    int id = stoi(line.substr(0, colon_index)) + 1;
    rule_t rule = parse_rule(line.substr(colon_index + 2, line.size()));
    rules[id] = rule;
  }

  // step 1: eliminate start symbol from RHS
  rule_t s0 = vector<vector<int>>{1};
  rules[0] = s0;

  // step 2: eliminate null, unit and useless productions

  return 0;
}
