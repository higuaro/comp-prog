#include <iostream>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  int fx, fy, fz; fx = fy = fz = 0;
  while (n--) {
    int x, y, z; std::cin >> x >> y >> z;
    fx += x; fy += y; fz += z;
  }
  std::cout << (fx || fy || fz ? "NO" : "YES") << '\n';
  return 0;
}       
