#include <bits/stdc++.h>
using namespace std;
void bfs(const vector<unordered_set<int>>& g, const int target, 
    unordered_set<int>& visited,
    int node, int depth = 0) {
  if (visited.count(node)) return;
  if (node == target) {
    cout << depth << endl;
    exit(0);
  }
  visited.insert(node);
  for (auto child : g[node]) {
    bfs(g, target, child, depth + 1);
  }
}
int main() {
  int ox[] = {-1, 0, 1, 0};
  int oy[] = { 0,-1, 0, 1};
  int h, w; cin >> h >> w;
  int ci, cj; cin >> ci >> cj;
  int di, dj; cin >> di >> dj;
  ci--; cj--; di--; dj--;
  vector<string> s(h, "");
  for (int i = 0; i < h; i++)
    cin >> s[i];
  vector<int> a(h * w, 0);
  int colors = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i * w + j] || s[i][j] == '#') continue;
      
      unordered_set<int> to_explore;
      stack<pair<int, int>> ss;
      ss.push({i, j});
      to_explore.insert(i * w + j);
      while (!ss.empty()) {
        auto [ii, jj] = ss.top(); ss.pop();
        a[ii * w + jj] = colors;
        for (int k = 0; k < 4; k++) {
          int iii = ii + ox[k];
          int jjj = jj + oy[k];
          if (!to_explore.count(iii * w + jjj) 
              && (0 <= iii && iii < h && 0 <= jjj && jjj < w)
              && s[iii][jjj] == '.' 
              && !a[iii * w + jjj]) {
            ss.push({iii, jjj});
            to_explore.insert(iii * w + jjj);
          }
        }
      }

      colors++;
    }
  }
  colors--;

  if (a[ci * w + cj] == a[di * w + dj]) {
    cout << 0 << endl;
    return 0;
  }

//for (int i = 0; i < h; i++) {
//  for (int j = 0; j < w; j++) {
//    cout << a[i * w + j];
//  }
//  cout << '\n';
//}
//cout << endl << colors << endl;

  vector<unordered_set<int>> g(colors + 1, unordered_set<int>());
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int current_color = a[i * w + j];
      if (!current_color) continue;
      for (int ii = -2; ii <= 2; ii++) {
        for (int jj = -2; jj <= 2; jj++) {
          int iii = i + ii;
          int jjj = j + jj;
          if (iii < 0 || h <= iii || jjj < 0 || w <= jjj)
            continue;
          int color = a[iii * w + jjj];
          if (color && color != current_color) 
            g[current_color].insert(color);
        }
      }
    }
  }

// for (int c = 1; c <= colors; c++) {
//   cout << c << ':';
//   for (int c2 : g[c]) {
//     cout << c2 << ',';
//   }
//   cout << endl;
// }

  int src = a[ci * w + cj];
  int dest = a[di * w + dj];

  queue<pair<int, int>> q;
  q.push({src, 0});
  unordered_set<int> visited;
  while (!q.empty()) {
    auto [node, depth] = q.front(); q.pop();
    if (node == dest) {
      cout << depth << endl;
      return 0;
    }
    auto children = g[node]; 
    for (auto child : children) {
      if (!visited.count(child)) {
        q.push({child, depth + 1});
      }
    }
    visited.insert(node);
  }

  cout << -1 << endl;
  return 0;
}
