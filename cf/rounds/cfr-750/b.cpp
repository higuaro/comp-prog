#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t n; cin >> n;
    int64_t _1 = 0, _0 = 0;
    for (int i = 0; i < n; i++) {
      int ai; cin >> ai;
      if (ai == 0) _0++;
      if (ai == 1) _1++;
    }
    int64_t total = _1 * (1LL << _0);
    cout << total << endl;
  }
  return 0;
}
