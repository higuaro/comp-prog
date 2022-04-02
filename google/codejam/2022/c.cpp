#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, T; cin >> T; t = T;
  while (t--) {
    int n; cin >> n;
    vector<int> s(n, 0);
    for (auto& si : s) cin >> si;
    sort(begin(s), end(s));
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] > k) k++;
    }
    cout << "Case #" << (T - t) << ": " << k << '\n';
  }
  return 0;
}
