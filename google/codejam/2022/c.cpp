#include <bits/stdc++.h>
using namespace std;
int main() {
  const int M = 1e6;
  int t, T; cin >> T; t = T;
  array<int, M> s;
  while (t--) {
    int n; cin >> n;
    int max_si = 0;
    for (int i = 0; i < n; i++) {
      int si; cin >> si;
      s[i] = si;
      max_si = max(max_si, si);
    }
    sort(begin(s), begin(s) + n);
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] > k) k++;
      if (k >= max_si) 
        break;
    }
    cout << "Case #" << (T - t) << ": " << k << '\n';
  }
  return 0;
}
