#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
const int oo = numeric_limits<int>::max();
typedef map<tuple<int, int, int>, bool> cube_t;
void remove_any(string& s, const string& r) {
  for (char c : r)
    replace(begin(s), end(s), c, ' ');
}
struct region_t {
  int x1, x2, y1, y2, z1, z2;
  int v;
};
int main() {
  string line;
  vector<region_t> regions;
  while (getline(cin, line)) {
    remove_any(line, "=.,xyz");
    istringstream iss(line);
    int min_xx, max_xx, min_yy, max_yy, min_zz, max_zz;
    string is_on;
    iss >> is_on >> min_xx >> max_xx >> min_yy >> max_yy >> min_zz >> max_zz;
    region_t r;
    r.x1 = min_xx; r.x2 = max_xx; 
    r.y1 = min_yy; r.y2 = max_xx; 
    r.z1 = min_zz; r.z2 = max_zz;
    r.v = is_on == "on";
    regions.push_back(r);
  }

  const int n = regions.size();
  vector<int> xs(n, 0), ys(n, 0), zs(n, 0);
  for (auto r : regions) {
    xs.push_back(r.x1); xs.push_back(r.x2);
    ys.push_back(r.y1); ys.push_back(r.y2);
    zs.push_back(r.z1); zs.push_back(r.z2);
  }
  sort(begin(xs), end(xs)); sort(begin(ys), end(ys)); sort(begin(zs), end(zs));

  unordered_map<int, int> cx, cy, cz;
  for (int i = 0; i < n; i++) {
    cx[xs[i]] = i; cy[ys[i]] = i; cz[zs[i]] = i;
  }

  cube_t cube;
  for (auto r : regions) {
    for (int xi = cx[r.x1]; xi <= cx[r.x2]; xi++)
      for (int yi = cy[r.y1]; yi <= cy[r.y2]; yi++)
        for (int zi = cz[r.z1]; zi <= cz[r.z2]; zi++)
          cube[{xi, yi, zi}] = r.v;
  }

  uint64_t total_on = 0; 
  for (auto [cxyz, on] : cube) {
    auto [xi, yi, zi] = cxyz;
    if (xi + 1 >= n || yi + 1 >= n || zi >= 1) continue;
    if (on) total_on += (xs[xi + 1] - xs[xi] + 1) * (ys[yi + 1] - ys[yi] + 1) * (zs[zi + 1] - zs[zi] + 1);
  }
  cout << total_on << endl;
  return 0;
}
