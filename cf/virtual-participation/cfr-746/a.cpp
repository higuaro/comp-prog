#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t n, h; cin >> n >> h;
    vector<int64_t> a(n, 0);
    for (auto& ai : a) cin >> ai;
    sort(begin(a), end(a), greater<int64_t>());
    int a01 = a[0] + a[1];
    int k = h / a01;
    int r = h % a01;
    int i = 0;
    while (r > 0) {
      r -= a[(i++) % 2];
    }
    cout << (2 * k + i) << '\n';
  }
  return 0;
}
