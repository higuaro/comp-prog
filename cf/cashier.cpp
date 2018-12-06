#include <iostream>
#include <cstdlib>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  uint64_t n, l, a; std::cin >> n >> l >> a;
  uint64_t pt = 0, aa = 0;
  while (n--) {
    uint64_t ti, li; std::cin >> ti >> li;
    aa += (ti - pt) / a;
    pt = ti + li;
  }
  aa += (l - pt) / a;
  std::cout << aa << '\n';
    
  return 0;
}
