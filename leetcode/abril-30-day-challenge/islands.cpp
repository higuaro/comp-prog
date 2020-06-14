#include <bits/stdc++.h>
using namespace std;
int numIslands(vector<vector<char>>& grid) {
  if (grid.empty()) return 0;
  int h = grid.size();
  int w = grid[0].size();
  vector<bool> visited(w * h, false);   
  int islands = 0;
  int oi[] = { -1, 0, 1, 0 };
  int oj[] = { 0, -1, 0, 1 };
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (visited[i * w + j] || grid[i][j] == '0') continue;
      islands++;
      stack<pair<int, int>> q;
      q.push({i, j});
      while (!q.empty()) {
        auto [ii, jj] = q.top(); q.pop();
        visited[ii * w + jj] = true;
        for (int k = 0; k < 4; k++) {
          int iii = ii + oi[k];
          int jjj = jj + oj[k];
          if (0 <= iii && iii < h && 
              0 <= jjj && jjj < w &&
            !visited[iii * w + jjj] && grid[iii][jjj] == '1') {
            cout << iii << ',' << jjj << endl;
            q.push({iii, jjj});
          }
        }
      }
    }
  }
  return islands;
}

int main() {
  vector<vector<char>> grid;
  string line;
  while (cin >> line)
    grid.push_back(vector<char>(begin(line), end(line)));

  cout << "processing" << endl;
  cout << numIslands(grid) << endl;
  return 0;
}
