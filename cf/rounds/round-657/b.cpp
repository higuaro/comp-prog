#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t l, r, m; cin >> l >> r >> m;
    for (int64_t a = l; a <= r; a++) {
      int64_t div = m / a;
      int64_t rem = (div + 1) * a - m;
cout << "a = " << a << " div: " << div << " rem: " << rem << endl;
      if (rem <= (r - l)) {
        int64_t c = r;
        int64_t b = r - rem;
int64_t n = (m - b + c) / a;
int64_t mm = n * a + b - c;
cout << "1)   n=" << n << ", m: " << mm << '=' << m << endl;
        cout << a << ' ' << b << ' ' << c << endl;
        break;
      }

      rem = m % a;
      if (rem <= (r - l) && (m - rem) > 0) {
        int64_t b = r;
        int64_t c = r - rem;
int64_t n = (m - b + c) / a;
int64_t mm = n * a + b - c;
cout << "2)   n=" << n << ", m: " << mm << '=' << m << endl;
        cout << a << ' ' << b << ' ' << c << endl;
        break;
      }
    }
  }
  return 0;
}
