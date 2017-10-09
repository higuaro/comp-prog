#include <iostream>
#include <cstring>
#include <bitset>
#include <list>
#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <map>
using namespace std;

typedef unsigned int uint;
typedef list< pair<uint, uint> > listOfPair;

template<int N> void sieveOfAtkin(bitset<N>& primes) {
    primes.reset();
    const size_t MAX = N;
    const size_t ROOT_MAX = static_cast<size_t>( sqrtf(MAX) );

    typedef unsigned long ulong;
    for (size_t x = 1; x < ROOT_MAX; x++) {
        for (size_t y = 1; y < ROOT_MAX; y++) {
            ulong x_2 = x * x;
            ulong y_2 = y * y;
            ulong n = 4 * x_2 + y_2;
            ulong n_mod_12 = n % 12;            
            if (n <= MAX && (n_mod_12 == 1 || n_mod_12 == 5))
                primes[n] = !primes[n];

            n = 3 * x_2 + y_2;
            if (n <= MAX && (n % 12) == 7)
                primes[n] = !primes[n];

            n = 3 * x_2 - y_2;           
            if (x > y && n <= MAX && (n % 12) == 11)
                primes[n] = !primes[n];
        }
    }
    
    for (size_t n = 5; n < ROOT_MAX; n++) {
        if (primes[n]) {
            ulong k = n * n;
            for (size_t j = k; j <= MAX; j += k) primes[j] = false;
        }
    }
    primes[2] = true;
    primes[3] = true;
}

template<int N> list<uint> buildPrimeList(const bitset<N>& sieve) {
    list<uint> primes;
    for (int i = 2; i < N; i++) 
        if (sieve[i]) primes.push_back(i);
    return primes;
}

int main() { 
    const uint N = 1000000;
    bitset<N> sieve;
    sieveOfAtkin<N>(sieve);
            
    const int LIMIT = 1000;
    uint max = 0;
    int maxA = 0, maxB = 0;
    for (int a = -LIMIT; a < LIMIT; a++) { 
        for (int b = -LIMIT; b < LIMIT; b++) {
            bool keepCalculating = true;
            uint count = 0;           
            for (uint n = 0; keepCalculating; n++) { 
                int y = (n * n) + (a * n) + b;
                if (sieve[abs(y)]) { 
                    count++;
                } else {
                    keepCalculating = false;
                }
            }
            if (count > max) { 
                maxA = a;
                maxB = b;
                max = count;
            }
        }
    }
    
    cout << max << " " << maxA << " " << maxB << endl;
    cout << maxA * maxB << endl; 
}