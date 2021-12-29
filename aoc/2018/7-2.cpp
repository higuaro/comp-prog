#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  typedef priority_queue<char, vector<char>, greater<char>> queue;

  set<char> nodes;
  map<char, set<char>> node_children;
  map<char, set<char>> node_requirements;

  set<char> is_child;
  string line;
  while (getline(cin, line, '\n')) {
    // pos 8 in vim
    // |    +-- pos 13 in vim         pos 44 in vim
    // |    |                              |
    // v    v                              v
    // Step F must be finished before step E can begin.
    char parent = line[13 - 8];
    char child = line[44 - 8];

    nodes.insert(parent); nodes.insert(child);
    node_children[parent].insert(child);
    node_requirements[child].insert(parent);
    is_child.insert(child);
  }

  set<char> origins;
  set_difference(nodes.begin(), nodes.end(), is_child.begin(),
      is_child.end(), inserter(origins, origins.end()));

  queue available;
  for (auto origin : origins) available.push(origin);

  const int initial_cost = 60;
  const int num_workers = 5;

  int second = 0;
  array<int, num_workers> workers{0};
  array<char, num_workers> worker_node{0};
  set<char> nodes_processed;
  do {
    for (int i = 0; i < num_workers && !available.empty(); i++) {
      if (!workers[i]) {
        char node = available.top(); available.pop();
        worker_node[i] = node;
        workers[i] = static_cast<int>(node - 'A') + 1 + initial_cost;
      }
    }

    clog << setw(4) << second << ' ';
    for (int i = 0; i < num_workers; i++)
      clog << (worker_node[i] ? worker_node[i] : '.') << ' ';
    clog << endl;

    for (int i = 0; i < num_workers; i++)
      if (workers[i]) {
        workers[i]--;
        if (!workers[i]) {
          char processed_node = worker_node[i];
          worker_node[i] = 0;
          nodes_processed.insert(processed_node);

          for (auto child : node_children[processed_node]) {
            bool all_requirements_completed = true;
            for (auto requirement : node_requirements[child]) {
              if (!nodes_processed.count(requirement)) {
                all_requirements_completed = false;
                break;
              }
            }
            if (all_requirements_completed) available.push(child);
          }
        }
      }
    second++;
  } while (nodes_processed.size() < nodes.size());
  cout << second << endl;
  return 0;
}
