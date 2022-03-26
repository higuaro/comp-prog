#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int r, c; cin >> r >> c;
    int64_t m = max(r, c);
    int64_t n = m - 1;
    int64_t m2 = m * m;
    int64_t n2 = n * n;
    bool up = max(static_cast<int64_t>(0), m) & 1;
    int64_t k = abs(r - m) + c;
    cout << (up ? n2 + k : m2 - k + 1) << endl;
  }
  return 0;
}
