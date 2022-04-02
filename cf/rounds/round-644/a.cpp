#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    if (b < a) swap(a, b);
    int l = 2 * a > b ? 2 * a : b;
    cout << l * l << endl;
  }
  return 0;
}
