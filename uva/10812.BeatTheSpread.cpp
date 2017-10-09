#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <limits>
#include <iomanip>
#include <cstdint>

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("10812.BeatTheSpread.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    int n;
    std::cin >> n;
    while (--n >= 0) {
        int64_t s, d;
        std::cin >> s >> d;
        int64_t b = (s - d) / 2;
        if (b < 0) {
            std::cout << "impossible" << std::endl;
        } else {
            int64_t a = s - b;
            if (a >= 0 && a + b == s && abs(a - b) == d) {
                std::cout << a << ' ' << b << std::endl;
            } else {
                std::cout << "impossible" << std::endl;
            }
        }
    }
    return 0;
}