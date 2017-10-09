#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	std::ifstream fis("world_scramble.in");
	std::cin.rdbuf(fis.rdbuf());
#endif
	std::string line;
	while (std::getline(std::cin, line)) {
		std::istringstream iss(line);
		std::string word = "";
		size_t count = 0;
		do  {
			std::reverse(word.begin(), word.end());
			std::cout << (count++ > 1 ? " " : "") << word;
		} while(iss >> word);
		std::cout << std::endl;
	}
	return 0;
}