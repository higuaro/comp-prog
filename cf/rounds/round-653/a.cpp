#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int x, y, n; cin >> x >> y >> n;
    int r; int k = n;
    if ((r = k % x) == y)
      cout << k << endl;
    else {
      if (r > y) 
        cout << (k - (r - y)) << endl;
      else
        cout << (k - r - (x - y)) << endl;
    }
  }
  return 0;
}
