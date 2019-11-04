#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  const int MAX = 1e4;
  while (t--) {
    array<int, MAX + 1> found{0};
    int m, n; cin >> m >> n;
    bool solved = false;
    for (int i = 1; i <= n; i++) {
      int c; cin >> c;
      if (solved || c > m) continue;
      if (found[m - c]) {
        int i1 = found[m - c], i2 = i;
        if (i1 > i2) swap(i1, i2);
        cout << i1 << ' ' << i2 << endl;
        solved = true;
      }
      found[c] = i;
    }
  }
  return 0;
}

