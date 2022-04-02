#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  multiset<int, greater<int>> h;
  for (int i = 0; i < n; i++) {
    int hi; cin >> hi;
    h.insert(hi);
  }
  for (int i = 0; i < m; i++) {
    int ti; cin >> ti;
    auto it = h.lower_bound(ti);
    if (it != h.end()) {
      h.erase(it);
      cout << *it << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}

