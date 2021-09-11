#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, q; cin >> l >> q;
  set<int> cuts;
  for (int i = 0; i < q; i++) {
    int ci, xi; cin >> ci >> xi;
    if (ci == 1) {
      cuts.insert(xi);
      continue;
    }
    auto ri = cuts.lower_bound(xi);
    auto li = lower_bound(rbegin(cuts), rend(cuts), xi, greater<int>());
    int rr = ri == cuts.end() ? l : *ri;
    int ll = li == cuts.rend() ? 0 : *li;
    cout << rr - ll << endl;
  }
  return 0;
}
