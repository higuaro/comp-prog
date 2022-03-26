#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    if ((a + b) % 3) {
      cout << "NO" << endl;
      continue;
    } 
    if (a == b) {
      cout << "YES" << endl;
      continue;
    }
    if (a > b) swap(a, b);
    int third = (a + b) / 3;
    //cout << "1 / 3 = " << third << endl;
    //cout << "(2 / 3) = " << 2 * third << endl;
    //cout << "b = " << b << endl;

    cout << (b > 2 * third ? "NO" : "YES") << endl;
  }
  return 0;
}
