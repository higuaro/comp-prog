#include <bits/stdc++.h>
using namespace std;
int count(const vector<string>& g) {
  set<char> q;
  for (auto person : g) {
    for (auto ans : person)
      q.insert(ans);
  }
  return q.size();
}
int main() {
  int sum = 0;
  vector<string> g;
  string line;
  while (getline(cin, line, '\n')) {
    if (line.empty()) {
      sum += count(g);
      g.clear();
      continue;
    }
    g.push_back(line);
  }
  sum += count(g);
  cout << sum << endl;
  return 0;
}
