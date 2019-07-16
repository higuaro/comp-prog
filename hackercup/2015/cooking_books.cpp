#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>

int toInt(const std::string& n, const int BASE = 10) {
	int size = static_cast<int>(n.size());
	int r = 0;
	for (int i = 0, base = 1; i < size; i++, base *= BASE) {
		r += base * (n[size - 1 - i] - '0');
	}
	return r;
}

std::pair<int, int> findMinMax(const std::string& n) {
	int size = static_cast<int>(n.size());
	const int N = toInt(n);
	int min = N;
	int max = N;

	for (int i = 0; i < size; i++) { 
		// Copy input
		std::string tmp(n);
		for (int j = 0; j < size; j++) {
			if (i == j) continue;
			if (i == 0 && tmp[j] == '0') continue;
			if (j == 0 && tmp[i] == '0') continue;

			std::swap(tmp[i], tmp[j]);
			int k = toInt(tmp);
			if (k < min) min = k;
			if (k > max) max = k;

			// Return tmp to original state
			std::swap(tmp[j], tmp[i]);
		}
	}

	return std::make_pair(min, max);
}

int R_main(int argc, char* argv[]) {
	std::ifstream fis("cooking_the_books.txt");
	std::ofstream fos("cooking_books.out");
	
	int n;
	fis >> n;
	fis.ignore(256, '\n');

	int cases = 1;
	while (n--) { 
		std::string line;
		std::getline(fis, line); 
		std::pair<int, int> minAndMax = findMinMax(line);
		fos << "Case #" << cases << ": " << minAndMax.first << ' ' << minAndMax.second;
		if (n > 0) fos << std::endl;
		cases++;
	}
	return 0;
} 