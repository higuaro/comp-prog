#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cmath>
using namespace std;

const uint64_t oo = numeric_limits<uint64_t>::max();
uint64_t dp[26][26][41][26];

bool is_dp_value_set(char c1, char c2, int d) {
  for (int i = 0; i < 26; i++) 
    if (dp[c1 - 'A'][c2 - 'A'][d][i] != oo) return true;
  return false;
}

unordered_map<char, uint64_t> map_from_dp(char c1, char c2, int d) {
  unordered_map<char, uint64_t> m;
  for (int i = 0; i < 26; i++) 
    if (dp[c1 - 'A'][c2 - 'A'][d][i] != oo)
      m[i + 'A'] = dp[c1 - 'A'][c2 - 'A'][d][i];
  return m;
}

void update_dp_from_map(char c1, char c2, int d, unordered_map<char, uint64_t>& m) {
  for (auto [c, v] : m) 
    dp[c1 - 'A'][c2 - 'A'][d][c - 'A'] = v;
}

unordered_map<char, uint64_t> merge(
    unordered_map<char, uint64_t>& m1, unordered_map<char, uint64_t> m2) {
  unordered_map<char, uint64_t> r;
  for (char c = 'A'; c <= 'Z'; c++) r[c] = m1[c] + m2[c];
  return r;
}

unordered_map<char, uint64_t> solve(unordered_map<string, char>& rules, 
    char c1, char c2, int d) {
  if (d == 0) {
    unordered_map<char, uint64_t> result;
    result[c1]++; result[c2]++;
    return result;
  }
  if (is_dp_value_set(c1, c2, d))
    return map_from_dp(c1, c2, d);
  char c3 = rules[string{c1, c2}];
  auto result1 = solve(rules, c1, c3, d - 1);
  auto result2 = solve(rules, c3, c2, d - 1);

  result2[c3]--;
  auto merged = merge(result1, result2);
  update_dp_from_map(c1, c2, d, merged);
  return merged;
}

int main() {
  for (int i = 0; i < 26; i++) 
    for (int j = 0; j < 26; j++)
      for (int d = 0; d < 41; d++) 
        for (int k = 0; k < 26; k++)
          dp[i][j][d][k] = oo;

  string line;
  string template_; cin >> template_;
  unordered_map<string, char> rules;

  while (getline(cin, line)) {
    if (line == "") continue;
    replace(begin(line), end(line), '-', ' ');
    replace(begin(line), end(line), '>', ' ');
    istringstream iss(line);
    string s; char p;
    while (iss >> s >> p) 
      rules[s] = p;
  }

  unordered_map<char, uint64_t> total;
  for (int i = 0; i < template_.size() - 1; i++) {
    char c1 = template_[i];
    char c2 = template_[i + 1];
    auto result = solve(rules, c1, c2, 40);
    if (i > 0) result[c1]--;
    total = merge(total, result);
  }

  uint64_t _min = oo;
  uint64_t _max = -oo;
  for (auto [c, v] : total) {
    if (!v) continue;
    _min = min(_min, v);
    _max = max(_max, v);
  }
  cout << _max - _min << endl;
  return 0;
}
