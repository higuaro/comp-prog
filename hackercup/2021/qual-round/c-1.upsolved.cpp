#include <bits/stdc++.h>
using namespace std;
int solve_node(const vector<int>& c, const vector<vector<int>>& g, 
    unordered_set<int>& visited, int node) {
  auto& children = g[node];
  int best = 0;
  visited.insert(node);
  for (auto child : children)
    if (!visited.count(child)) 
      best = max(best, solve_node(c, g, visited, child));
  return c[node] + best;
}
int solve(const vector<int>& c, const vector<vector<int>>& g) {
  auto& children = g[0];
  vector<int> sum_children;
  unordered_set<int> visited{0};
  for (auto child : children)
    sum_children.push_back(solve_node(c, g, visited, child));
  sort(begin(sum_children), end(sum_children), greater<int>());
  int nc = sum_children.size();
  return c[0] + (nc ? sum_children[0] : 0) + (nc > 1 ? sum_children[1] : 0);
}
int main() {
  int t; cin >> t;
  int T = 1;
  while (t--) {
    int n; cin >> n;
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
      int a, b; cin >> a >> b; a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    cout << "Case #" << T++ << ": " << solve(c, g) << endl;
  }
  return 0;
}
