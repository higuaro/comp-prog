#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, l, r, k; cin >> n >> l >> r >> k;
    vector<int> a(n, 0);
    for (auto& ai : a) cin >> ai;
    sort(begin(a), end(a));

    int count = 0;
    for(auto ai : a) {
      if (l <= ai && ai <= r) {
        k -= ai;
        if (k < 0) break;
        count++;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
