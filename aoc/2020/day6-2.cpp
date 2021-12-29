#include <bits/stdc++.h>
using namespace std;
int count(const vector<string>& group) {
  map<char, int> questions;
  for (auto person : group) {
    for (auto question : person)
      questions[question]++;
  }
  int people = group.size();
  int total = 0;
  for (auto [q, count] : questions)
    if (count == people) total++;
  return total;
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
