#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    vector<int64_t> rgb(3, 0);
    for (auto& rgbi : rgb) cin >> rgbi;
    sort(begin(rgb), end(rgb));
    if (rgb[0] == rgb[1] || rgb[1] == rgb[2]) {
      cout << rgb[1] << endl;
    } else {
      const int64_t oo = numeric_limits<int64_t>::max();
      int64_t m = oo;
      int64_t d1 = rgb[2] - rgb[1];
      int64_t d2 = rgb[2] - rgb[0];
      int64_t d3 = rgb[1] - rgb[0];
      if (!(d1 % 3) && (d1 / 3) <= rgb[0])
        m = min(m, rgb[2]);
      if (!(d2 % 3) && (d2 / 3) <= rgb[1])
        m = min(m, rgb[2]);
      if (!(d3 % 3))
        m = min(m, rgb[1]);
      cout << (m == oo ? -1 : m) << endl;
    }
  }
  return 0;
}
