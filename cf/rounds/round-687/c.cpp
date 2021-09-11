#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, p, k; cin >> n >> p >> k;
    string a; cin >> a;
    int kx, ky; cin >> kx >> ky;

    int ans = numeric_limits<int>::max();
    for (int y = 0; y < p; y++) {
      int x = 0;
      bool skip = false;
      for (int i = y + p - 1; i < n - y; i += k) {
        if (a[i] != '1') {
          x++;
          //if ((ky * y + kx * x) > ans) {
          //  skip = true;
          //  break;
          //}
        }
      }
      if (!skip) {
        ans = min(ans, (kx * x) + (ky * y));
        cout << "ks =" << kx << ',' << ky << endl;
        cout << ans << '=' << x << ',' << y << endl;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
