#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    ll even_ps = 0LL;
    ll odd_ps = 0LL;
    for (int i = 0; i < n; i++) {
      int p; cin >> p;
      if (p & 1) odd_ps++;
    }
    even_ps = n - odd_ps;
    int m; cin >> m;
    ll even_qs = 0LL;
    ll odd_qs = 0LL;
    for (int i = 0; i < m; i++) {
      int q; cin >> q;
      if (q & 1) odd_qs++;
    }
    even_qs = m - odd_qs;
    ll total = even_ps * even_qs + odd_ps * odd_qs;
    cout << total << endl;
  }

  return 0;
}
