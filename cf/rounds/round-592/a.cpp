#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int min_pens = a / c + ((a % c) ? 1 : 0);
    int min_pencils = b / d + ((b % d) ? 1 : 0);
    int items = min_pens + min_pencils;
    if (items > k)
      cout << -1 << endl;
    else 
      cout << min_pens << ' ' << min_pencils << endl;
  }

  return 0;
}
