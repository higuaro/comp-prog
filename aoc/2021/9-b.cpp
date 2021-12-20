#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <queue>
#include <set>
using namespace std;

int basin_size(const vector<string>& lines, int io, int jo) {
  char c = lines[io][jo];
  int h = lines.size();
  int w = lines[0].size();
  int o[] = {-1, 0, 1, 0, -1};
  set<pair<int, int>> visited;
  visited.insert({io, jo});
  queue<pair<int, int>> q; q.push({io, jo});
  uint64_t size = 1;
  do {
    auto [i, j] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int ii = i + o[k];
      int jj = j + o[k + 1];
      if (ii < 0 || ii >= h || jj < 0 || jj >= w || visited.count({ii, jj}))
        continue;
      char cc = lines[ii][jj];
      if (cc == '9') continue;
      if (cc > c) {
        visited.insert({ii, jj});
        size++;
        q.push({ii, jj});
      }
    }
  } while (!q.empty());
  return size;
}
int main() {
  vector<string> lines;
  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }
  int h = lines.size();
  int w = lines[0].size();

  vector<pair<int, int>> low_points;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c = lines[i][j];
      int o[] = {-1, 0, 1, 0, -1};
      bool is_low = true;
      for (int k = 0; k < 4; k++) {
        int ii = i + o[k];
        int jj = j + o[k + 1];
        if (0 <= ii && ii < h && 0 <= jj && jj < w) {
          if (lines[ii][jj] <= c) {
            is_low = false;
            break;
          }
        }
      }
      if (is_low)
        low_points.push_back({i, j});
    }
  }
  cout << low_points.size() << endl;

  vector<int> sizes;
  for (auto [i, j] : low_points)
    sizes.push_back(basin_size(lines, i, j));
  sort(begin(sizes), end(sizes), greater<>());

  cout << sizes[0] << endl;
  exit(1);
  cout << sizes[0] * sizes[1] * sizes[2] << endl;
  return 0;
}
