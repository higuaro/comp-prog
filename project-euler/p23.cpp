#include <iostream>
#include <cstring>
#include <bitset>
#include <list>
#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>
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

listOfPair getPrimeFactors(const uint n, const list<uint>& primes) { 
    list<uint>::const_iterator ite = primes.begin();
    list<uint>::const_iterator end = primes.end();
    
    listOfPair factors;
    uint a = n;
    for (; ite != end && (*ite) <= a; ++ite) { 
        uint b = *ite;
        int count = 0;
        while ((a % b) == 0 && a > 1) { 
            a /= b;
            count++;
        }
        if (count > 0) factors.push_back(pair<uint, uint>(b, count));
    }
    // It's prime
    if (factors.empty()) factors.push_back(pair<uint, uint>(n, 1));
    return factors;
}

uint myPow(const uint n, const uint power) { 
    uint r = 1;
    for (uint i = 0; i < power; i++, r *= n);
    return r;
} 

//                                   p^n+1 - 1 
// o(p^n) = 1 + p^2 + ... + p^n-1 = ---------- 
//                                     p - 1
uint sumOfProperDivisors(const uint n, const listOfPair& primeFactors) { 
    listOfPair::const_iterator ite = primeFactors.begin(), end = primeFactors.end();
    uint sum = 1;

    for(; ite != end; ++ite) { 
        uint p = (*ite).first;
        uint a = (*ite).second;
        sum *= ((myPow(p, a + 1) - 1) / (p - 1));
    }
    return sum - n;
}

bool isAbundant(const uint n, const list<uint>& primes) {
    listOfPair factors = getPrimeFactors(n, primes);
    uint sumDivs = sumOfProperDivisors(n, factors);
    return sumDivs > n;
}

int main() { 
    const uint N = 30000;
    bitset<N> sieve;
    sieveOfAtkin<N>(sieve);
    list<uint> primes = buildPrimeList<N>(sieve);

    const uint LIMIT = 28123;
    bool integers[N];
    memset(integers, 0, sizeof(integers) / sizeof(bool));
    
    vector<uint> abundants;

    for (uint n = 12; n < LIMIT; n++)
        if (isAbundant(n, primes)) { 
            abundants.push_back(n);
            
            vector<uint>::iterator ite, end = abundants.end();
            for(ite = abundants.begin(); ite != end; ++ite)
                if ((*ite) + n < N)
                    integers[(*ite) + n] = true;
        }
    
    long total = 0;
    for (uint i = 0; i < 28123; i++) 
        if (!integers[i]) total += i;

    cout << total << endl;
    return 0;
}