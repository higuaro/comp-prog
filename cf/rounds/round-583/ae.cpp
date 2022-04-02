#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, e; cin >> n >> d >> e;
  int ans = n;
  for (int i = 0; i * 5 * e <= n; i++) {
    int t = n - i * 5 * e;
    if ((t % d) < ans) {
      clog << i << " 5 euro bills, t = " << t << " t mod d" << (t % d) << endl;
      ans = t % d;
    }
  }
  cout << ans << endl;
  return 0;
}
