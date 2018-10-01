#include <iostream>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int w; std::cin >> w;
  std::cout << (w < 4 || (w & 1) ? "NO" : "YES") << '\n';
  return 0; 
}
