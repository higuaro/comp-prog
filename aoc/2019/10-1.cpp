#include <bits/stdc++.h>
using namespace std;

int scan_line(vector<vector<int>>& map, set<pair<int, int>>& visited,
    int rows, int cols, int asteroid_row, int asteroid_column, int row, int column) {
  if (visited.count(make_pair(row, column))) return 0;

  bool found = false;
  int vr = row, vc = column;
  do {
    if (map[vr][vc]) found = true;
    visited.insert(make_pair(vr, vc));
    vr += (row - asteroid_row);
    vc += (column - asteroid_column);
  } while (0 <= vr && vr < rows && 0 <= vc && vc < cols);

  return found;
}

int hor_scan_line(vector<vector<int>>& map, set<pair<int, int>>& visited,
    int rows, int cols, int asteroid_row, int asteroid_column, int row) {
  int asteroids_found = 0;
  for (int column = 0; column < cols; column++) {
    asteroids_found += scan_line(map, visited, rows, cols,
        asteroid_row, asteroid_column, row, column);
  }
  return asteroids_found;
}
int vert_scan_line(vector<vector<int>>& map, set<pair<int, int>>& visited,
    int rows, int cols, int asteroid_row, int asteroid_column, int column) {
  int asteroids_found = 0;
  for (int row = 0; row < rows; row++) {
    asteroids_found += scan_line(map, visited, rows, cols,
        asteroid_row, asteroid_column, row, column);
  }
  return asteroids_found;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> map;
  int rows = 0, cols = 0;
  string line;
  while (getline(cin, line, '\n')) {
    if (!cols) cols = static_cast<int>(line.size());
    vector<int> row;
    for (auto c : line) {
      row.push_back(c == '#' ? 1 : 0);
    }
    map.push_back(row);
  }
  rows = static_cast<int>(map.size());

  int max = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {

      if (map[r][c]) {
        int asteroids = 0;
        set<pair<int, int>> visited;

        for (int lc = c + 1; lc < cols; lc++)
          asteroids += vert_scan_line(map, visited, rows, cols, r, c, lc);
        for (int lc = c - 1; lc >= 0; lc--)
          asteroids += vert_scan_line(map, visited, rows, cols, r, c, lc);

        for (int lr = r + 1; lr < rows; lr++)
          asteroids += hor_scan_line(map, visited, rows, cols, r, c, lr);
        for (int lr = r - 1; lr >= 0; lr--)
          asteroids += hor_scan_line(map, visited, rows, cols, r, c, lr);

        if (asteroids > max) {
          max = asteroids;
          // clog << r << ' ' << c << ' ' << max << endl;
        }
      }
    }
  }
  cout << max << endl;
  return 0;
}
