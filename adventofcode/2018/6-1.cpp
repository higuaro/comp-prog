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
  table<int> min_dist = create_table<int>(W, H, oo);
  for (int iy = 0; iy < H; iy++)
    for (int jx = 0; jx < W; jx++)
      for (auto [x, y] : coords)
        min_dist[iy][jx] = ::min(min_dist[iy][jx], abs(x - jx) + abs(y - iy));

  // Label the points accoding their Manhattan distances
  table<int> labels = create_table<int>(W, H, oo);
  for (int iy = 0; iy < H; iy++)
    for (int jx = 0; jx < W; jx++) {
      int label = 1;
      for (auto [x, y] : coords) {
        int d = abs(x - jx) + abs(y - iy);
        if (d == min_dist[iy][jx])
          labels[iy][jx] = labels[iy][jx] == oo ? label : 0;
        label++;
      }
    }

  // Check the borders, those on the borders can be ignored
  set<int> ignore{};
  for (int j = 0; j < W; j++) {
    int label1 = labels[0][j];
    int label2 = labels[H - 1][j];
    if (!ignore.count(label1)) ignore.insert(label1);
    if (!ignore.count(label2)) ignore.insert(label2);
  }
  for (int i = 0; i < H; i++) {
    int label1 = labels[i][0];
    int label2 = labels[i][W - 1];
    if (!ignore.count(label1)) ignore.insert(label1);
    if (!ignore.count(label2)) ignore.insert(label2);
  }

  int total_labels = static_cast<int>(coords.size());
  map<int, int> areas;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      areas[labels[i][j]]++;

  int max_area = _oo;
  for (int label = 1; label < total_labels; label++) {
    if (ignore.count(label)) continue;
    int area = areas[label];
    if (area > max_area) max_area = area;
  }
  cout << "max area = " << max_area << endl;
  return 0;
}
