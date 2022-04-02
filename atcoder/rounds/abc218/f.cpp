#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n, 0));
  vector<pair<int, int>> e;
  for (int i = 0; i < m; i++) {
    int s, t; cin >> s >> t;
    g[s][t] = 1;
    g[t][s] = 1;
    e.emplace_back(s, t);
  }

  return 0;
}
