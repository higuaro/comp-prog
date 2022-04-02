#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  cout << fixed << setprecision(12);
  if (!b) {
    cout << 1.0 << ' ' << 0.0 << endl;
    return 0;
  }
  long double alpha = atan2(b, a);
  cout << cos(alpha) << ' ' << sin(alpha) << endl;
  return 0;
}
