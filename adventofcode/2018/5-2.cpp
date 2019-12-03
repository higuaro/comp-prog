#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string line; cin >> line;
  map<char, stack<char>> chars;
  for (auto c : line)
    if (!chars.count(tolower(c))) chars[tolower(c)];

  for (auto c : line) {
    for (auto& e : chars) {
      if (e.first == tolower(c)) continue;
      if (e.second.empty()) {
        e.second.push(c);
        continue;
      }
      if (abs(e.second.top() - c) == 32)
        e.second.pop();
      else
        e.second.push(c);
    }
  }
  size_t min = numeric_limits<size_t>::max();
  for (auto e : chars) {
    if (e.second.size() < min)
      min = e.second.size();
  }
  cout << min << std::endl;
  return 0;
}
