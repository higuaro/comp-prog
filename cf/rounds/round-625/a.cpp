#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> r, b;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    r.push_back(t);
  }
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    b.push_back(t);
  }
  int rs = 0, bs = 0;
  for (int i = 0; i < n; i++) {
    if (r[i] && !b[i]) rs++;
    if (b[i] && !r[i]) bs++;
  }

  if (!rs) {
    cout << -1 << endl;
  } else {
    if (rs > bs) {
      cout << 1 << endl;
    } else if (rs == bs) {
      cout << 2 << endl;
    } else {
      cout << ((bs - rs) / rs) + ((bs - rs) % rs ? 1 : 1) + 1 << endl;
    }
  }
  return 0;
}
