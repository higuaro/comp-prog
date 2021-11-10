#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n, {0, 0});
    for (int i = 0; i < n; i++) {
      int ai; cin >> ai;
      a[i] = {ai, i};
    }
    sort(begin(a), end(a));
    bool possible = true;
    for (int i = 0; i < n; i++) {
      auto [ai, j] = a[i];
      int d = abs(i - j);
      //cout << ai << " dist " << d << ": " << (i - x) << ',' << (i + x) << '\n';
      if (d && ((i - x) < 0 && (i + x) >= n)) {
        possible = false;
        break;
      }
    }
    cout << (possible ? "YES" : "NO") << '\n';
  }
  return 0;
}
