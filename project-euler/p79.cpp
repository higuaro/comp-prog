#include <bits/stdc++.h>

template<typename T, size_t N, size_t M>
using table = std::array<std::array<T, M>, N>;

template<typename T, std::size_t N, std::size_t M = N>
bool is_node(size_t n, const table<T, N, M>& graph) {
  for (size_t j = 0; j < N; j++)
    if (graph[n][j]) return true;
  for (size_t i = 0; i < M; i++)
    if (graph[i][n]) return true;
  return false;
}

template<typename T, std::size_t N, std::size_t M = N>
void topo_visit(const table<T, N, M>& graph, const size_t node, 
                std::array<bool, N>& visited, std::stack<size_t>& stack) {
  if (visited[node]) return;

  size_t node_index = 0;
  for (auto out_edge : graph[node]) {
    if (out_edge > 0)
      topo_visit(graph, node_index, visited, stack);
    node_index++;
  }
  visited[node] = true;
  stack.push(node);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::ifstream fis("keylog.txt");
  std::string keylog;
  const size_t N = 10;
  table<unsigned, N, N> graph{0};

  while (fis >> keylog) {
    #define D(n) auto d##n = static_cast<size_t>(keylog[n] - '0')
    D(0); D(1); D(2);
    #undef D
    graph[d0][d1]++; graph[d1][d2]++;
  }

  std::stack<size_t> stack;
  std::array<bool, N> visited{false};
  for (size_t node = 0; node < N; node++)
    if (is_node(node, graph))
      topo_visit(graph, node, visited, stack);

  while (!stack.empty()) {
    std::cout << stack.top();
    stack.pop();
  }
  std::cout << std::endl;
  return 0;
}
