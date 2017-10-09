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

void debug(std::list<size_t>& primeList, std::vector< std::vector<size_t> > memo, const size_t size = 4) {
    const size_t SIZE = size;
    std::cout << std::setw(SIZE) << '-' << " ";     
    std::cout << std::setw(SIZE) << '-' << " ";
    
    for (auto prime : primeList) std::cout << std::setw(SIZE) << prime << " ";
    std::cout << std::endl;    
    for (size_t i = 0; i <= primeList.size(); ++i) {
        if (i > 0) { 
            auto iter = primeList.begin();
            std::advance(iter, i - 1);
            std::cout << std::setw(SIZE) << *iter << " ";
        } else {
            std::cout << std::setw(SIZE) << '-' << " ";
        }

        for (size_t j = 0; j <= primeList.size(); ++j) { 
            std::cout << std::setw(SIZE) << memo[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const size_t N = 1000000;

    std::bitset<N> primes;
    fillSieveOfAtkin(primes);

    std::list<size_t> primeList = createPrimeList(primes, N);

    const size_t M = primeList.size() + 1;
    
    int** memo = new int*[M];
    for (size_t i = 0; i < M; i++)
        memo[i] = new int[i + 1];

    size_t index = 1;
    size_t maxLength = 0;
    size_t mPrime = 0;
    bool shouldBreakOuterLoop = false;
    for (auto prime : primeList) { 
        for (int i = static_cast<int>(index); i >= 1; i--) { 
            size_t v = memo[i][index] = prime + memo[i][index - 1];
            
            if (v > N) {
                shouldBreakOuterLoop = true;
                break;
            }
            
            if (primes[v]) {
                if (index - i > maxLength) {
                    maxLength = index - i;
                    mPrime = v;
                }
            }
        }
        if (shouldBreakOuterLoop) break;
        index++;
    }
    
    std::cout << maxLength + 1 << std::endl;
    // Just to debug
    std::cout << mPrime << std::endl;        

    for (size_t i = 0; i < M; i++) {
        std::cerr << "deleting subarray " << i << std::endl;
        delete[] memo[i];
    }    
    std::cerr << "deleting memo array " << std::endl;    
    delete[] memo;
    
    return 0;
}
