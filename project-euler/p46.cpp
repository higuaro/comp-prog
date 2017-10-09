#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <bitset>
#include <stdexcept>
#include <ctime>
#include <list>
#include <algorithm>
#include <iomanip>

template<size_t N> void fillSieveOfAtkin(std::bitset<N>& primes) {
    primes.reset();
    const size_t ROOT_MAX = static_cast<size_t>( sqrtf(N) );

    typedef unsigned long ulong;
    for (size_t x = 1; x < ROOT_MAX; x++) {
        for (size_t y = 1; y < ROOT_MAX; y++) {
            ulong x_2 = x * x; 
            ulong y_2 = y * y;

            ulong n = 4 * x_2 + y_2;
            ulong n_mod_12 = n % 12;            
            if (n <= N && (n_mod_12 == 1 || n_mod_12 == 5)) primes[n] = !primes[n];

            n = 3 * x_2 + y_2;
            if (n <= N && (n % 12) == 7) primes[n] = !primes[n];

            n = 3 * x_2 - y_2;           
            if (x > y && n <= N && (n % 12) == 11) primes[n] = !primes[n];
        }
    }
    
    for (size_t n = 5; n < ROOT_MAX; n++) {
        if (primes[n]) {
            ulong k = n * n;
            for (size_t j = k; j <= N; j += k) primes[j] = false;
        }
    }
    primes[2] = primes[3] = true;
}

template<size_t N> std::list<size_t> createPrimeList(const std::bitset<N>& primes, const size_t K = N) { 
    std::list<size_t> primeList;
    
    primeList.push_back(2);
    for (size_t i = 3; i < K; i += 2)
        if (primes[i]) primeList.push_back(i);
    return primeList;
}

int main() {
    const size_t N = 1000000;

    std::bitset<N> primes;
    fillSieveOfAtkin(primes);

    std::list<size_t> primeList = createPrimeList(primes, N);
    
    for (size_t n = 9; ; n += 2) { 
        if (primes[n]) continue;
        bool isGolbachNumber = false;
        for (auto p : primeList) {
            if (p > n) break;
            
            bool found = false;
            for (size_t k = 1; k < n; k++) {
                auto g = p + 2 * (k * k);
                if (g == n) {
                    found = true;
                    break;
                }
                if (g > n) break;
            }
            if (found) {
                isGolbachNumber = true;
                break;
            } 
        }
        if (!isGolbachNumber) {
            std::cout << n << std::endl;
            break;
        }
    }
    
    return 0;
}
