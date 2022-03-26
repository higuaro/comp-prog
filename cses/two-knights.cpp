#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t n; cin >> n;
  for (uint64_t k = 1; k <= n; k++) {
    uint64_t k2 = k * k;
    uint64_t t = (k2 * (k2 - 1) / 2) - 4 * (k - 2) * (k - 1);
    cout << t << endl;
  }
  return 0;
}
