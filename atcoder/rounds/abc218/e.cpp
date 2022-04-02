#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(vector<vector<int>>& adj, int v, int p = -1) {
  visited[v] = true;
  tin[v] = low[v] = timer++;
  for (int to : adj[v]) {
    if (to == p) continue;
    if (visited[to]) {
      low[v] = min(low[v], tin[to]);
    } else {
      dfs(adj, to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v])
        cout << v << " - " << to << endl;
          //IS_BRIDGE(v, to);
    }
  }
}

void find_bridges(const int n, vector<vector<int>>& adj) {
  timer = 0;
  visited.assign(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (!visited[i])
      dfs(adj, i);
  }
}
int main() {
  int n, m; cin >> n >> m;

  map<pair<int, int>, int> c;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int ai, bi, ci; cin >> ai >> bi >> ci;
    c[{ai, bi}] = ci;
    ai--; bi--;
    adj[ai].push_back(bi);
    adj[bi].push_back(ai);
  }
  find_bridges(n, adj);
  return 0;
}
