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

uint getDigitCount(uint p) { 
    uint i = 0;
    while (p > 0) { 
        p /= 10; 
        i++;
    }
    return i;
}

uint pow(uint n, uint p) { 
    uint r = 1;
    for (uint i = 0; i < p; i++, r *= n);
    return r;
}

// First, get the digit at the left
//  c = p / 10 ^ numDigits (example: for 89191, c = 8)
// Then, substract the digit at the left,
//  p = p - c * 10 ^ numDigits (example: for 89191 - 80000 = 9191)
// Shift the new number to the left multiplying by 10 (example: 9191 * 10 = 91910)
// Last, add the digit c (example: 91910 + 8 = 91918)
uint rot(uint p, uint n) { 
    uint base = pow(10, n - 1);
    uint c = p / base;
    return (p - (c * base)) * 10 + c;
}

int main() { 
    const uint N = 1000000;
    bitset<N> sieve;
    sieveOfAtkin<N>(sieve);
    list<uint> primes = buildPrimeList<N>(sieve);
    map<uint, bool> primesMap;
    
    list<uint>::iterator ite, end;
    end = primes.end();
    for (ite = primes.begin(); ite != end; ++ite) 
        primesMap[*ite] = true;
    
    uint totalCirculars = 0;
    for (ite = primes.begin(); ite != end; ++ite) { 
        uint p = *ite;
        uint n = getDigitCount(p);
        bool isCircular = true;
        uint len = n - 1;
        for (uint i = 0; i < len; i++) { 
            uint pr = rot(p, n);
            if (!primesMap.count(pr)) {
                isCircular = false;
                break;
            } else { 
                p = pr;
            }
        }
        if (isCircular) totalCirculars++;
    }    
    cout << totalCirculars << endl;
}