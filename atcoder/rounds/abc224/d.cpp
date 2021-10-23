#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int oo = 9999999;
const string win = "123456780";

vector<string> children(const string state, const vector<vector<int>>& al) {
  vector<string> c;
  int pos_empty = state.find('0');
  vector<int> moves = al[pos_empty];
  for (auto move : moves) {
    string s(state);
    swap(s[move], s[pos_empty]);
    c.push_back(s);
  }
  return c;
}

int main() {
  int m; cin >> m;
  vector<vector<int>> al(10, vector<int>());
  for (int i = 0; i < m; i++) {
    int ui, vi; cin >> ui >> vi;
    al[ui - 1].push_back(vi - 1);
    al[vi - 1].push_back(ui - 1);
  }

  string state = "000000000";
  for (int i = 1; i <= 8; i++) {
    int pos_pi; cin >> pos_pi;
    state[pos_pi - 1] = i + '0';
  }

  queue<pair<string, int>> q;
  q.push({state, 0});
  gp_hash_table<string, bool> in_queue;
  gp_hash_table<string, bool> visited;
  int best = oo;
  while (!q.empty()) {
    auto [state, step] = q.front(); q.pop();
    if (state == win) 
      best = min(best, step);
    visited[state] = true;
    for (auto c : children(state, al)) {
      if (visited.find(c) != visited.end()) continue;
      pair<string, int> node{c, step + 1};
      if (in_queue.find(c) != in_queue.end()) continue;
      q.push(node);
      in_queue[c] = true;
    }
  }
  cout << (best == oo ? -1 : best) << endl;
  return 0;
}
