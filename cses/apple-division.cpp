#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for (auto& ai : a) cin >> ai; 

  int64_t best = 1e9 + 1;
  int nn = 1 << n;
  for (int k = 0; k < nn; k++) {
    int64_t s0 = 0, s1 = 0;
    for (int i = 0; i < n; i++) {
      if ((k >> i) & 1)
        s1 += a[i];
      else
        s0 += a[i];
    }
    best = min(best, abs(s1 - s0));
  }
  cout << best << endl;
  return 0;
}
