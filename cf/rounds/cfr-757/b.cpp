#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<pair<int64_t, int64_t>> a(n, {0, 0});
    for (int i = 0; i < n; i++) {
      int64_t ai; cin >> ai;
      a[i] = {ai, i};
    }
    sort(begin(a), end(a), greater<pair<int64_t, int64_t>>());

    int64_t d = 1;
    int64_t dist = 0LL;
    vector<int64_t> b(n, 0);
    for (int i = 0; i < n; i++) {
      dist += a[i].first * 2 * d;
      b[a[i].second] = i & 1 ? -d : d;
      if (i & 1) d++;
    }
    cout << dist << '\n';
    cout << "0 ";
    for (auto bi : b) 
      cout << bi << ' ';
    cout << '\n';
  }
  return 0;
}
