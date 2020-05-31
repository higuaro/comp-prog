#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int64_t> a;
  bool zero_found = false;
  for (int i = 0; i < n; i++) {
    uint64_t ai; cin >> ai;
    if (!ai) zero_found = true;
    a.push_back(ai);
  }
  if (zero_found) {
    cout << 0 << endl;
    return 0;
  }

  int64_t m = static_cast<int64_t>(1e18);
  int64_t r = 1ULL;
  for (int i = 0; i < n; i++) {
    r *= a[i];
    if (r > m) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << r << endl;
  return 0;
}
