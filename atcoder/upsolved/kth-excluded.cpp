#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q; cin >> n >> q;
  vector<int64_t> a(n, 0), c(n, 0);
  cin >> a[0]; c[0] = a[0] - 1;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    c[i] = c[i - 1] + a[i] - a[i - 1] - 1;
  }

  for (int qi = 0; qi < q; qi++) {
    int64_t k; cin >> k;
    if (k < a[0]) {
      cout << k << endl;
    } else if (k > c[n - 1]) {
      cout << a[n - 1] + (k - c[n - 1]) << endl;
    } else {
      auto pci = lower_bound(begin(c), end(c), k);
      --pci;
      auto i = distance(begin(c), pci);
      cout << a[i] + (k - c[i]) << endl;
    }
  }
  return 0;
}
