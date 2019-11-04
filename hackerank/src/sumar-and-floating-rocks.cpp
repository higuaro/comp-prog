#include <bits/stdc++.h>
using namespace std;
inline int64_t sign(int64_t n) {
  return n < 0 ? -1 : 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int64_t x1, y1; cin >> x1 >> y1;
    int64_t x2, y2; cin >> x2 >> y2;
    int64_t dy = y2 - y1;
    int64_t dx = x2 - x1;
    if (dx && dy) {
      int64_t d = __gcd(abs(dy), abs(dx));
      dy /= d; dx /= d;
    } 
    dy = !dx ? sign(dy) : dy;
    dx = !dy ? sign(dx) : dx;
    int64_t x = x1 + dx, y = y1 + dy;
    int64_t c = 0;
    while (!(x == x2 && y == y2)) {
      x += dx; y += dy;
      c++;
    }
    cout << c << endl;
  }
  return 0;
}
