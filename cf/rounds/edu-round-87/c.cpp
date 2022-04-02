#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int v = 2 * n;
    const double pi = 3.141592653589793238462643383279502;
    double alpha = (2 * pi) / v;
    double h = 0.5 / tan(alpha / 2.0);
    cout.precision(9);
    cout << fixed << 2 * h << endl;
  }
  return 0;
}
