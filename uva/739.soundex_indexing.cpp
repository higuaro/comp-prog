#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstring>

std::string spaces(int n) {
	return std::string(n, ' ').c_str();
}

char getCode(const char c) {
	switch (c) {
		case 'B': case 'P': case 'F': case 'V':
			return '1';
		case 'C': case 'S': case 'K': case 'G': case 'J': case 'Q': case 'X': case 'Z':
			return '2';
		case 'D': case 'T':
			return '3';
		case 'L': 
			return '4';
		case 'M': case 'N':
			return '5';
		case 'R': 
			return '6';
	}
	return 0;
}

std::string soundex(const std::string& name) {
	char code[5];
	memset(code, '0', 4);
	code[0] = name[0];
	code[4] = 0;
	int len = static_cast<int>(name.size());
	for (int i = 1, j = 1; i < len; ++i) {
		char c = getCode(name[i]);
		char cp = getCode(name[i - 1]);
		if (c == cp) continue;
		if (c) code[j++] = c;
		if (j == 4) break;
	}
	return std::string(code);
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	std::ifstream fis("soundex_indexing.in");
	std::cin.rdbuf(fis.rdbuf());

	std::freopen("soundex_indexing.out", "w", stdout);
#endif
	std::string line;
	bool titlePrinted = false;
	while (std::getline(std::cin, line)) {
		if (!titlePrinted) {
			std::printf("%sNAME %sSOUNDEX CODE\n", spaces(9).c_str(), spaces(20).c_str());
			titlePrinted = true;
		}
		std::printf("%s%s", spaces(9).c_str(), line.c_str());
		std::printf("%s%s\n", spaces(25 - line.size()).c_str(), soundex(line).c_str());
	}
	std::printf("%sEND OF OUTPUT\n", spaces(19).c_str());
	return 0;
}
         