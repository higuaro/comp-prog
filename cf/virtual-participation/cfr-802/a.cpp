#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    int64_t sum = m * (m + 1) / 2;
    int v = 2 * m;
    for (int k = 1; k < n; k++) {
      sum += v;
      v += m;
    }
    cout << sum << '\n';
  }
  return 0;
}
