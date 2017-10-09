#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

long getCycleLength(long n, std::vector<long>& cycleLengths) {
    long length = 1;
    while (n != 1) {
        if (n & 1) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }

        if (n < cycleLengths.size() && cycleLengths[n]) {
            return length + cycleLengths[n];
        }
        length++;        
    }
    return length;
}

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("3n+1.in");
    std::cin.rdbuf(fis.rdbuf());
#endif

    const int MAX = 1000000;
    std::vector<long> cycleLengths(MAX, 0);

    for (int i = 1; i < MAX; i++) { 
        cycleLengths[i] = getCycleLength(i, cycleLengths);
    }

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream ss(line);
        int i, j;
        ss >> i >> j;

        int ii = i, jj = j;
        if (i > j) { 
            std::swap(ii, jj);
        }

        long max = 0;        
        for (int k = ii; k <= jj; k++) {
            max = std::max(max, cycleLengths[k]);
        }
        std::cout << i << ' ' << j << ' ' << max << std::endl;
    }
    
    return 0;
}
