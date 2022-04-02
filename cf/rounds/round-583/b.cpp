#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int g, b, n; cin >> g >> b >> n;
  if (n <= min(g, b)) {
    cout << n + 1 << endl;
  } else if (n == g + b) {
    cout << 1 << endl;
  } else if (min(g, b) < n) {
    int mi = min(g, b);
    int ma = max(g, b);
    int d = ma - mi;
    int d_n = n - mi;
    if (d < d_n) mi -= d_n;
    cout << mi + 1 << endl;
  }
  return 0;
}
