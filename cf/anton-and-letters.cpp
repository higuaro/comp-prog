#include <set>
#include <iostream>
#include <string>
#include <algorithm>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string line;
	std::getline(std::cin, line);
	std::set<char> chars;
	
	for (auto c : line) {
		switch (c) {
			case ' ':
			case ',':
			case '\t':
			case '\n':
			case '{':
			case '}': break;
			default:
				chars.insert(c);
		}
	}
	std::cout << chars.size() << '\n';
	return 0;
}
