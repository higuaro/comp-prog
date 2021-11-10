#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t n; cin >> n;
    if (n & 1) {
      int64_t l = (n - 1) / 2;
      cout << l << ' ' << (l + 1) << '\n';
    } else {
      cout << -(n - 1) << ' ' << n << '\n';
    }
  }
  return 0;
}
