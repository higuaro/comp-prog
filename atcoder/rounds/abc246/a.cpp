#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> xs(3, 0);
  vector<int> ys(3, 0);
  for (int i = 0; i < 3; i++)
    cin >> xs[i] >> ys[i];
  auto [min_x, max_x] = minmax_element(begin(xs), end(xs));
  auto [min_y, max_y] = minmax_element(begin(ys), end(ys));
  vector<pair<int, int>> v{ {*min_x, *min_y}, {*max_x, *min_y}, {*max_x, *max_y}, {*min_x, *max_y} };
  for (int i = 0; i < 4; i++) {
    auto [xi, yi] = v[i];
    bool found = false;
    for (int j = 0; j < 3; j++) {
      int x = xs[j];
      int y = ys[j];
      if (x == xi && y == yi) {
        found = true;
        break;
      }
    }
    if (!found) {
      cout << xi << ' ' << yi << endl;
      return 0;
    }
  }
  
  return 0;
}
