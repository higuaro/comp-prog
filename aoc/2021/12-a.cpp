#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<string, unordered_set<string>> adj_list_t;
struct node_t {
  node_t* parent;
  string cave;
  node_t(node_t* parent, const string& cave) : parent(parent), cave(cave) {}
  bool visited(const string& cave) {
    node_t* np = this;
    while (np != nullptr) {
      if (np->cave == cave) return true;
      np = np->parent;
    }
    return false;
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
      if (islower(c[0]) && node->visited(c))
        continue;
      q.push(new node_t(node, c));
    }
  }
  cout << end << endl;
  return 0;
}
