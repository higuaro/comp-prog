#include <bits/stdc++.h>
using namespace std;
struct rule_t {
  pair<int, int> range1;
  pair<int, int> range2;
  string label;
};
bool operator<(const rule_t r1, const rule_t r2) {
  return r1.label < r2.label;
}
pair<int, int> parse_interval(const string& inter) {
  auto dash_pos = inter.find('-');
  auto left = inter.substr(0, dash_pos);
  auto right = inter.substr(dash_pos + 1);
  return { stoi(left), stoi(right) };
}
vector<rule_t> parse_rules() {
  string line;
  vector<rule_t> rules;
  while (getline(cin, line, '\n')) {
    if (line.empty()) return rules;
    int colon_index = line.find(':');
    istringstream iss(line.substr(colon_index + 1));
    string interval1, _, interval2;
    iss >> interval1 >> _ >> interval2;
    rule_t rule;
    rule.label = line.substr(0, colon_index);
    rule.range1 = parse_interval(interval1);
    rule.range2 = parse_interval(interval2);
    rules.push_back(rule);
  }
  return rules;
}
vector<int> parse_ticket() {
  // discard "your ticket:"
  string _; getline(cin, _, '\n');
  vector<int> ticket;
  string line; getline(cin, line, '\n');
  istringstream iss(line);
  string token;
  while (getline(iss, token, ','))
    ticket.push_back(stoi(token));
  // discard empty line
  getline(cin, _, '\n');
  return ticket;
}
vector<vector<int>> parse_nearby() {
  // discard "nearby tickets:"
  string _; getline(cin, _, '\n');
  vector<vector<int>> nearby;
  string line;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string token;
    vector<int> ticket;
    while (getline(iss, token, ','))
      ticket.push_back(stoi(token));
    nearby.push_back(ticket);
  }
  return nearby;
}
bool is_reduced(const vector<set<rule_t>>& candidates) {
  for (auto& group : candidates)
    if (group.size() > 1)
      return false;
  return true;
}
int main() {
  auto rules = parse_rules();
  auto ticket = parse_ticket();
  auto nearby = parse_nearby();

  const int N = 1000;
  bitset<N> valid;
  for (auto& rule : rules) {
    auto [l1, r1] = rule.range1;
    for (int n = l1; n <= r1; n++)
      valid.set(n);
    auto [l2, r2] = rule.range2;
    for (int n = l2; n <= r2; n++)
      valid.set(n);
  }

  vector<vector<int>> valid_tickets{ticket};
  for (auto& ticket : nearby) {
    bool is_valid = true;
    for (auto value : ticket)
      if (!valid[value]) {
        is_valid = false;
        break;
      }
    if (is_valid)
      valid_tickets.push_back(ticket);
  }

  int num_valid_tickets = valid_tickets.size();
  int fields = valid_tickets[0].size();
  int num_rules = rules.size();
  vector<set<rule_t>> candidates(num_rules, set<rule_t>());
  for (int r = 0; r < num_rules; r++) {
    auto rule = rules[r];
    auto [l1, r1] = rule.range1;
    auto [l2, r2] = rule.range2;
    for (int field = 0; field < fields; field++) {
      bool candidate_field = true;
      for (int ticket = 0; ticket < num_valid_tickets; ticket++) {
        int val = valid_tickets[ticket][field];

        if (!((l1 <= val && val <= r1) || (l2 <= val && val <= r2))) {
          candidate_field = false;
          break;
        }
      }
      if (candidate_field)
        candidates[field].insert(rule);
    }
  }

  set<rule_t> processed;
  while (!is_reduced(candidates)) {
    // search a candidate that is by itself
    rule_t candidate;
    for (auto& group : candidates) {
      auto first_rule = *group.begin();
      if (group.size() == 1 && !processed.count(first_rule)) {
        candidate = first_rule;
        break;
      }
    }

    for (int i = 0; i < fields; i++)
      if (candidates[i].size() > 1)
        candidates[i].erase(candidate);

    processed.insert(candidate);
  }

  uint64_t product = 1ULL;
  for (int field = 0; field < fields; field++) {
    rule_t rule = *candidates[field].begin();
    cout << rule.label << ": " << ticket[field] << endl;
    if (rule.label.find("departure") != string::npos)
      product *= ticket[field];
  }
  cout << product << endl;

  return 0;
}
