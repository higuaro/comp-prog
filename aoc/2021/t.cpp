#include <algorithm>
#include <vector>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <queue>
#include <fstream>
using namespace std;
const int o[] = {-1, 0, 1, 0, -1};
int size(const vector<string>& lines, const int w, const int h, int io, int jo) {
  queue<pair<int, int>> q; q.push({io, jo});
  set<pair<int, int>> visited;
  int s = 1;
  do {
    auto [i, j] = q.front(); q.pop();
    char c = lines[i][j];
    for (int k = 0; k < 4; k++) {
      int ii = i + o[k];
      int jj = j + o[k + 1];
      if (ii < 0 || ii >= h || jj < 0 || jj >= w || visited.count({ii, jj})) 
        continue;
      char cc = lines[ii][jj];
      if (cc == '9' || cc <= c) continue;
      q.push({ii, jj});
      s++;
    }
    visited.insert({i, j});
  } while (!q.empty());
  return s;
}
int main() {
  string line;
  vector<string> lines;
  ifstream fis("9.example.in");
  cin.rdbuf(fis.rdbuf());
  while (getline(cin, line)) {
    lines.push_back(line);
  }
  int h = lines.size();
  int w = lines[0].size();
  vector<pair<int, int>> low_points;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c = lines[i][j];
      bool is_low = true;
      for (int k = 0; k < 4; k++) {
        int ii = i + o[k];
        int jj = j + o[k + 1];
        if (0 <= ii && ii < h && 0 <= jj && jj < w && lines[ii][jj] <= c) {
          is_low = false;
          break;
        }
      }
      if (is_low) {
        low_points.push_back({i, j});
      }
    }
  }

  vector<int> sizes;
  for (auto [i, j] : low_points) 
    sizes.push_back(size(lines, w, h, i, j));
  sort(begin(sizes), end(sizes), greater<>());
  for (auto s : sizes) cout << "s: " << s << endl;
  cout << sizes[0] * sizes[1] * sizes[2] << endl;
  return 0;
}
