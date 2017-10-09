#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <algorithm>
#include <cmath>
#include <climits>

inline size_t sqr(size_t v) {
    return v * v;
}

int main() {
    int maxSolsFound = 0;
    int maxP = 0;
    for (size_t p = 1000; p >= 3; p--) { 
        int numSols = 0;
        for (size_t a = p - 2; a >= 1; a--) { 
            for (size_t b = a; b >= 1; b--) {
                size_t c = p - a - b;
                if (c && a + b > c && sqr(a) + sqr(b) == sqr(c)) {
                    // std::cout << "For p = " << p << ", {" << a << ", " << b << ", " << c "}" << std::endl;
                    std::printf("For p = %lu, {%lu, %lu, %lu}\n", p, a, b, c);
                    numSols++;
                }
            }
        }
        if (numSols > maxSolsFound) {
            maxSolsFound = numSols;
            maxP = p;
        }
    }
    std::cout << maxSolsFound << std::endl;
    std::cout << "for p = " << maxP << std::endl;
    return 0;
}
