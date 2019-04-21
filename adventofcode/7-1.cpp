#include <bits/stdc++.h>
using namespace std;

template<typename T, int N, int M>
using table = array<array<T, M>, N>;

typedef priority_queue<int, vector<int>, greater<int>> heap;

template<int N>
void visit(const table<bool, N, N>& graph, int node,
    heap& to_visit, map<int, int>& in_degree) {
  for (int n = 0; n < N; n++)
    if (n != node && graph[node][n]) {
      in_degree[n]--;
      if (!in_degree[n])
        to_visit.push(n);
    }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const int N = 26;
  table<bool, N, N> graph {false};

  map<int, int> in_degree;

  set<int> nodes;

  string line;
  while (getline(cin, line, '\n')) {
    // pos 8 in vim
    // |    +-- pos 13 in vim         pos 44 in vim
    // |    |                              |
    // v    v                              v
    // Step F must be finished before step E can begin.
    char s = line[13 - 8] - 'A';
    char d = line[44 - 8] - 'A';

    in_degree[d]++;
    graph[s][d] = true;

    nodes.insert(s);
    nodes.insert(d);
  }

  set<int> origins;
  for (auto node : nodes) {
    bool is_origin = true;
    for (int j = 0; j < N; j++)
      if (graph[j][node]) {
        is_origin = false;
        break;
      }
    if (is_origin)
      origins.insert(node);
  }

  heap to_visit{greater<int>()};
  for (int origin : origins)
    to_visit.push(origin);

  while (!to_visit.empty()) {
    int node = to_visit.top();
    to_visit.pop();
    visit<N>(graph, node, to_visit, in_degree);
    cout << static_cast<char>(node + 'A');
  }
  cout << '\n';

  return 0;
}
