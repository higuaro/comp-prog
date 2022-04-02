#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    uint64_t a, b, n, m;
    cin >> a >> b >> n >> m;
    if (!a && !b) {
      cout << "No" << endl;
      continue;
    }
    if (a && b && a >= n && a >= m && b >= n && b >= m) {
      cout << "Yes" << endl;
      continue;
    }
    if ((n > a && n > b) || (m > a && m > b)) {
      cout << "No" << endl;
      continue;
    }
    if (

    cout << (a + b >= n + m ? "Yes" : "No") << endl;
  }
  return 0;
}
