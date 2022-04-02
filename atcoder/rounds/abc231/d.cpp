#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest;
};
 
class Graph {
public:
  vector<vector<int>> adjList;

  Graph(vector<Edge> const &edges, int n) {
    adjList.resize(n);
    for (auto &edge: edges) {
      adjList[edge.src].push_back(edge.dest);
      adjList[edge.dest].push_back(edge.src);
    }
  }
};
 
bool dfs(Graph const &graph, int v, vector<bool> &discovered, int parent) {
  discovered[v] = true;
  for (int w: graph.adjList[v]) {
    if (!discovered[w]) {
      if (dfs(graph, w, discovered, v)) {
        return true;
      }
    } else if (w != parent) {
      return true;
    }
  }

  return false;
}
int main() {
  int n, m; cin >> n >> m;

  unordered_map<int, int> mm;
  vector<Edge> edges;
  for (int mi = 0; mi < m; mi++) {
    int a, b; cin >> a >> b;
    edges.push_back({a - 1, b - 1});
    mm[a]++; mm[b]++;
    if (mm[a] > 2 || mm[b] > 2) {
      //cout << a << '=' << g[a].size() << ", b=" << g[b].size() << endl;
      cout << "No" << endl;
      return 0;
    }
  }
  Graph graph(edges, n);
  vector<bool> discovered(n);
  cout << (dfs(graph, 0, discovered, -1) ? "No" : "Yes") << endl;
  return 0;
}
