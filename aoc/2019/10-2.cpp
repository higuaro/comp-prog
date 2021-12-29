#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> find_visibles(vector<vector<int>>& map,
    int rows, int cols, int ro, int co) {
  set<pair<int, int>> asteroids;
  for (int rf = 0; rf < rows; rf++) {
    for (int cf = 0; cf < cols; cf++) {
      if ((rf == ro && cf == co) || !map[rf][cf]) continue;

      int dx = cf - co; int dy = rf - ro;
      int gcd = __gcd(abs(dy), abs(dx));
      dx /= gcd; dy /= gcd;

      bool visible = true;
      int rt = rf, ct = cf;
      do {
        if (ct != co) ct -= dx;
        if (rt != ro) rt -= dy;
        if (rt < 0 || rt >= rows || ct < 0 || ct >= cols) break;
        if (rt == ro && ct == co) break;

        if (map[rt][ct]) {
          visible = false;
          break;
        }
      } while (rt != ro || ct != co);
      if (visible)
        asteroids.insert(make_pair(rf, cf));
    }
  }

  return asteroids;
}

double angle(int laser_row, int laser_col, pair<int, int>& p) {
  auto [row, col] = p;
  int dy = laser_row - row;
  int dx = col - laser_col;
  const float PI = 3.14159265;
  double angle = atan2(dy, dx) * 180 / PI;
  if (angle < 0) angle += 360.0;
  angle -= 90.0;
  return angle <= 0.0 ? abs(angle) : 360 - angle;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream fis("10.in");
  cin.rdbuf(fis.rdbuf());

  vector<vector<int>> map;
  int rows = 0, cols = 0;
  string line;
  int total_asteroids = 0;

  while (getline(cin, line, '\n')) {
    if (!cols) cols = static_cast<int>(line.size());
    vector<int> row;
    for (auto c : line) {
      total_asteroids += (c == '#');
      row.push_back(c == '#' ? 1 : 0);
    }
    map.push_back(row);
  }
  rows = static_cast<int>(map.size());

  int laser_row = 0, laser_col = 0;
  int max_visibles = -1;
  set<pair<int, int>> visibles;

  for (int ro = 0; ro < rows; ro++) {
    for (int co = 0; co < cols; co++) {
      if (!map[ro][co]) continue;

      auto asteroids = find_visibles(map, rows, cols, ro, co);

      if (static_cast<int>(asteroids.size()) > max_visibles) {
        max_visibles = asteroids.size();
        visibles = asteroids;
        laser_row = ro;
        laser_col = co;
      }
    }
  }

  int vaporized = 0;
  double laser_ang = 0.0;
  double new_angle = laser_ang;
  while (!visibles.empty()) {
    double min_diff = 999999.99;
    pair<int, int> to_vaporize;

    for (auto asteroid : visibles) {
      double ang = angle(laser_row, laser_col, asteroid);
      double diff = ang - laser_ang;
      if (diff < min_diff) {
        min_diff = diff;
        to_vaporize = asteroid;
        new_angle = ang;
      }
    }
    visibles.erase(to_vaporize);
    vaporized++;
    laser_ang = fmod(new_angle, 360.0);

    if (vaporized == 200)
      cout << "200th "
        << (100 * to_vaporize.second + to_vaporize.first) << endl;
  }

  return 0;
}
