#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  uint64_t x; cin >> x;
  x *= 100ULL;
  uint64_t ml = 0ULL;
  for (int i = 0; i < n; i++) {
    uint64_t v, p; cin >> v >> p;
    ml += v * p;
    if (ml > x) {
      cout << (i + 1) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
