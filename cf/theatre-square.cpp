#include <iostream>
#include <cstdint>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	uint64_t n, m, a; std::cin >> n >> m >> a;
	uint64_t w = (n / a) + (n % a ? 1 : 0);
	uint64_t h = (m / a) + (m % a ? 1 : 0);
  std::cout << w * h << '\n';	
	return 0;
}
