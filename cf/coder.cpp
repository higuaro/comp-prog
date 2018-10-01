#include <iostream>
#include <array>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	size_t n; std::cin >> n;
	std::cout << (n * n) / 2 + (n & 1) << '\n';
  std::array<char, 2> alph = {'C', '.'};
	for (size_t i = 0; i < n; i++) {
		size_t c = i & 1;
		for (size_t j = 0; j < n; j++)		
			std::cout << alph[c++ % 2];
		std::cout << '\n';
	}
	return 0;
}				
