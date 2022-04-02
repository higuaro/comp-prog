#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    if (n <= k) {
      cout << 1 << endl;
      continue;
    }
    int d = 1;
    int l = ceil(sqrt(n)) + 1;
    for (int q = 2; q <= l; q += (q == 2 ? 1 : 2)) {
      if (q > k) break;
      if (!(n % q)) {
        int p = 1;
        while (p * q <= k && !(n % (p * q))) {
          d = max(d, p * q);
          p++;
        }
      }
    }
    int packages = n / d;
    if (packages > d && packages < k) 
      swap(d, packages);
    cout << (n / d) << endl;
  }
  return 0;
}
