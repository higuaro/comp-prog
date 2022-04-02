#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    int64_t r = b;
    int64_t s = c - d;
    if (r >= a) {
      cout << b << endl;
      continue;
    }
    if (s <= 0LL) {
      cout << -1LL << endl;
      continue;
    }
    int64_t snoozes = ((a - r) / s) + ((a - r) % s ? 1LL : 0LL);
    cout << b + (snoozes * c) << endl;
  }
  return 0;
}
