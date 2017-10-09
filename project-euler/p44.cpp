#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <cstdio>

typedef unsigned long long int ulong64; 

bool isInt(double d) {
    double iPart;
    return modf(d, &iPart) == 0.0;
}

bool isPentagon(ulong64 p) {
    double disc = sqrt(24.0 * static_cast<double>(p) + 1.0);
    return isInt((disc + 1.0) / 6.0);
}

int main() {

    const size_t LIMIT = 999999999;
	
    size_t minD = std::numeric_limits<ulong64>::max();
    
    for (size_t j = 1; j < LIMIT; j++) {
        ulong64 pj = (j * (3LL * j - 1)) / 2LL;
        
        for (size_t k = j - 1; k >= 1; k--) {
            ulong64 pk = (k * (3LL * k - 1)) / 2LL;
            
            if (pk > pj) {
                std::swap(pk, pj);
            }

            ulong64 d = pj - pk;
            if (d >= minD) {
                break;
            } 

            if (isPentagon(pj + pk) && isPentagon(d)) {
                printf("%llu (%zu), %llu (%zu), | p - q | = %llu\n", pj, j, pk, k, d);
                // std::cout << p << "(" << ", " << q << " -> | p - q | = " << d << std::endl;
                minD = d;
            }
        }
    }
    std::cout << minD << std::endl;

    return 0;
}

