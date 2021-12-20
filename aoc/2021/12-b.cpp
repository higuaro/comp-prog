#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<string, unordered_set<string>> adj_list_t;
struct node_t {
  node_t* parent;
  string cave;
  node_t(node_t* parent, const string& cave) : parent(parent), cave(cave) {}
  bool can_visit(const string& cave) {
    unordered_map<string, int> count;
    count[cave] = 1;
    node_t* np = this;
    while (np != nullptr) {
      count[np->cave]++;
      np = np->parent;
    }
    bool has_double_visited = false;
    for (auto& [c, total] : count) {
      if (c == "start" || isupper(c[0])) continue;
      if (total > 2) return false;
      if (total == 2) {
        if (has_double_visited) return false;
        has_double_visited = true;
      }
    }
    return true;
  }
};
int main() {
  adj_list_t g;
  string line;
  while (getline(cin, line)) {
    replace(begin(line), end(line), '-', ' ');
    istringstream iss(line);
    string a, b; iss >> a >> b;
    g[a].insert(b); g[b].insert(a);
  }
  queue<node_t*> q; q.push(new node_t(nullptr, "start"));
  int end = 0;
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    auto& children = g[node->cave];
    for (auto& c : children) {
      if (c == "end") {
        end++;
        continue;
      }
      if (c == "start") continue;
      if (islower(c[0]) && !node->can_visit(c))
        continue;
      q.push(new node_t(node, c));
    }
  }
  cout << end << endl;
  return 0;
}
