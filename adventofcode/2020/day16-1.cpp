#include <bits/stdc++.h>
using namespace std;
pair<int, int> parse_interval(const string& inter) {
  auto dash_pos = inter.find('-');
  auto left = inter.substr(0, dash_pos);
  auto right = inter.substr(dash_pos + 1);
  return { stoi(left), stoi(right) };
}
vector<pair<int, int>> parse_rules() {
  string line;
  vector<pair<int, int>> rules;
  while (getline(cin, line, '\n')) {
    if (line.empty()) return rules;
    int colon_index = line.find(':');
    istringstream iss(line.substr(colon_index + 1));
    string interval1, _, interval2;
    iss >> interval1 >> _ >> interval2;
    rules.push_back(parse_interval(interval1));
    rules.push_back(parse_interval(interval2));
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
int main() {
  auto rules = parse_rules();
  auto ticket = parse_ticket();
  auto nearby = parse_nearby();

  const int N = 1000;
  int max_val = 0;
  for (auto [left, right] : rules)
    max_val = max(max_val, max(left, right));
  assert(max_val <= N);

  bitset<N> valid;
  for (auto [left, right] : rules)
    for (int n = left; n <= right; n++)
      valid.set(n);

  int sum_error = 0;
  for (auto& ticket : nearby)
    for (auto value : ticket)
      if (!valid[value])
        sum_error += value;
  cout << sum_error << endl;
  return 0;
}
