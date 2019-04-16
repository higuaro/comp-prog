#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

template<typename T>
using table = vector<vector<T>>;

template<typename T>
table<T> create_table(const size_t W, const size_t H, const T v = 0) {
  table<T> t;
  for (size_t i = 0; i < H; i++) {
    vector<T> row{};
    for (size_t j = 0; j < W; j++)
      row.push_back(v);
    t.push_back(row);
  }
  return t;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tx, ty; char _;
  vector<pair<int, int>> coords{};
  while (cin >> tx >> _ >> ty)
    coords.push_back(make_pair(tx, ty));

  const auto oo = numeric_limits<int>::max();
  const auto _oo = numeric_limits<int>::min();

  // Compute the bounding box
  pair<int, int> min{oo, oo}, max{_oo, _oo};
  for (auto [x, y] : coords) {
    if (x < min.first) min.first = x;
    if (x > max.first) max.first = x;
    if (y < min.second) min.second = y;
    if (y > max.second) max.second = y;
  }

  const int W = max.first - min.first + 1;
  const int H = max.second - min.second + 1;

  // Make coordenates relative to (W, H)
  for (auto& [rx, ry] : coords) {
    rx -= min.first;
    ry -= min.second;
  }

  // Compute the O(n^2) Manhattan distances
  table<int> dist = create_table<int>(W, H);
  for (int iy = 0; iy < H; iy++)
    for (int jx = 0; jx < W; jx++)
      for (auto [x, y] : coords)
        dist[iy][jx] += abs(x - jx) + abs(y - iy);

  // const int limit = 32;
  const int limit = 10000;
  int region_size = 0;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      if (dist[i][j] < limit) region_size++;

  cout << "region size = " << region_size << endl;
  return 0;
}
