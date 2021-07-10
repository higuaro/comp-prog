#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  const int oo = 1e6 + 9;
  vector<vector<int64_t>> g(n + 1, vector<int64_t>(n + 1, 0));
  vector<vector<int64_t>> d(n + 1, vector<int64_t>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    int ai, bi, ci; cin >> ai >> bi >> ci;
    g[ai][bi] = ci;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) d[i][j] = 0;
      else if (g[i][j]) d[i][j] = g[i][j];
      else d[i][j] = oo;
    }
  }

  int64_t f = 0ULL;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }

//for (int i = 1; i <= n; i++) {
//  for (int j = 1; j <= n; j++) {
//    if (d[i][j] == oo)
//      cout << "oo ";
//    else
//      cout << d[i][j] << ' ';
//  }
//  cout << endl;
//}
//cout << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f += d[i][j] >= oo ? 0 : d[i][j];
      }
    }
  }
  cout << f << endl;
  return 0;
}
