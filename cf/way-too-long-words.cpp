#include <iostream>
#include <string>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::string l;
	while (n--) {
		std::cin >> l;
		size_t len = l.size();
		std::cout << 
			(len <= 10 ? l : l[0] + std::to_string(len - 2) + l[len - 1]) << '\n';
	}
	return 0;
}	
