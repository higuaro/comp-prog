#include <iostream>
#include <string>
#include <array>
#include <algorithm>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	size_t k; std::cin >> k;
  std::cin.ignore(256, '\n');  
	std::array<size_t, 10> counts{0};
	for (size_t i = 0; i < 4; i++) {
		std::string line;
		std::getline(std::cin, line);
		for (size_t j = 0; j < 4; j++) {
      char c = line[j];  
      counts[c != '.' ? static_cast<size_t>(c - '0') : 0]++; 
    }
  }
  for (size_t i = 1; i < 10; i++) {
    if (counts[i] > 2 * k) {
      std::cout << "NO" << '\n';
      return 0;
    }
  }
  std::cout << "YES" << '\n';
	return 0;
}
