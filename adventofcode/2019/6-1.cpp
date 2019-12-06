#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, vector<pair<string, int>>> children;
  string line;

  while (getline(cin, line, '\n')) {
    istringstream ss(line);
    string a; getline(ss, a, ')');
    string b; getline(ss, b, '\n');

    children[a].push_back(make_pair(b, 0));
  }

  queue<pair<string, int>> q;
  q.push(make_pair("COM", 0));
  int total = 0;
  while (!q.empty()) {
    auto parent = q.front(); q.pop();
    total += parent.second;
    auto ch = children[parent.first];
    for (auto c : ch)
      q.push(make_pair(c.first, parent.second + 1));
  }

  cout << total << endl;
  return 0;
}
