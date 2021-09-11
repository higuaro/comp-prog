#include <bits/stdc++.h>
using namespace std;
int best;
void topos(const vector<vector<int>>& g, const int N,
    vector<int>& in, vector<char>& discovered, 
    vector<int>& path) {
  for (int v = 0; v < N; v++) {
    if (!in[v] && !discovered[v]) {
      for (auto u : g[v]) in[u]--;
      path.push_back(v);
      discovered[v] = 1;
      topos(g, N, in, discovered, path);

      for (auto u : g[v]) in[u]++;
      path.pop_back();
      discovered[v] = 0;
    }
  }
  
  if (path.size() == N) {
    int s = path[0];
    for (int i = 1; i < N; i++) {
      if (path[i] - s > best) {
      }
    }
  }
}
int main() {
  const int oo = numeric_limits<int>::max();
  best = -oo;
  int n, m; cin >> n >> m;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> g(n, {});
  vector<int> in(n, 0);
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    g[x - 1].push_back(y - 1);
    in[y - 1]++;
  }
  cout << best << endl;
  return 0;
}
