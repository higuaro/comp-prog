#include <bits/stdc++.h>
using namespace std;
int solve(const vector<pair<int, int>>& conds, 
    const vector<pair<int, int>>& opts, const int K) {
  int m = 0;
  int lim = 1 << (K - 1);
  for (int k = 0; k <= lim; k++) {
    vector<char> dishes(101, 0);
    for (int i = 0; i < K; i++) {
      int people = (k >> i) & 1;
      auto [c, d] = opts[i];
      dishes[people ? d : c] = 1;
    }
    int total = 0;
    for (auto [a, b] : conds) 
      if (dishes[a] && dishes[b]) total++;
    m = max(m, total);
  }
  return m;
}
int main() {
  int n, m; cin >> n >> m;
  vector<pair<int, int>> conds;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    conds.push_back({a, b});
  }
  int k; cin >> k;
  vector<pair<int, int>> options;
  for (int i = 0; i < k; i++) {
    int c, d; cin >> c >> d;
    options.push_back({c, d});
  }
  cout << solve(conds, options, k) << endl;
  return 0;
}
