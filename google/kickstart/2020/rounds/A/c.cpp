#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  int t = T;
  while (t--) {
    int n, k; cin >> n >> k;
    priority_queue<int> diffs;
    int prev_m; cin >> prev_m;
    for (int i = 1; i < n; i++) {
      int m; cin >> m;
      diffs.push(m - prev_m);
      prev_m = m;
    }

    while (k--) {
      int diff = diffs.top(); diffs.pop();
      if (diff == 1) break;
      diffs.push(diff / 2);
      diffs.push(diff / 2 + (diff & 1));
    }

    int total = diffs.empty() ? 1 : diffs.top();
    cout << "Case #" << (T - t) << ": " << total << endl;
  }

  return 0;
}
