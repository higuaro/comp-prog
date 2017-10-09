#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <stdexcept>
#include <ctime>
#include <algorithm>

using namespace std;
// 600851475143
// 600_851_475_143
// bool primes[10000000];

// bool primes[MAX];

template<size_t MAX>
std::bitset<MAX>* sieveOfAtkin() {
    const size_t ROOT_MAX = static_cast<size_t>(sqrt(MAX));
    std::bitset<MAX>* primes = new std::bitset<MAX>();
    for (size_t x = 1; x < ROOT_MAX; x++) {
        for (size_t y = 1; y < ROOT_MAX; y++) {
            const size_t x_2 = x * x;  const size_t y_2 = y * y;
            size_t n = 4 * x_2 + y_2;
            const size_t n_mod_12 = n % 12;
            if (n <= MAX && (n_mod_12 == 1 || n_mod_12 == 5)) (*primes)[n] = !(*primes)[n];
            n = 3 * x_2 + y_2;
            if (n <= MAX && (n % 12) == 7) (*primes)[n] = !(*primes)[n];
            n -= 2 * y_2;
            if (x > y && n <= MAX && (n % 12) == 11) (*primes)[n] = !(*primes)[n];
        }
    }
    for (size_t n = 5; n < ROOT_MAX; n++)
        if ((*primes)[n]) {
            const size_t k = n * n;
            for (size_t j = k; j <= MAX; j += k) (*primes)[j] = false;
        }
    (*primes)[2] = true; (*primes)[3] = true;
    return primes;
}

template<size_t MAX>
bitset<MAX>* sieveOfErathostenes() { 
    std::bitset<MAX>* primes = new std::bitset<MAX>();
    for (size_t i = 3; i < MAX; i++) (*primes)[i] = i & 1;
    (*primes)[0] = (*primes)[1] = false;
    (*primes)[2] = true;
    for (size_t i = 3L; i < MAX; i += 2) { 
        size_t start = i * i;
        if (start > MAX) break;
        for (size_t j = start; j < MAX; j += i) (*primes)[j] = false; 
    }
    return primes;
}

template<size_t MAX>
bool isPrimeSieve(int n, const std::bitset<MAX>& sieve) {
    return n == 1 ? false : (n & 1 ? sieve.test(n) : n == 2);
}

bool isPrimeBruteForce(long long n) { 
    if (n == 2 || n == 1) return true;
    if (!(n & 1)) return false;
    double r = sqrt(n);
    long r2 = static_cast<long>(r);
    for (int i = 3; i < r2; i += 2) if (!(n % i)) return false;
    return true;
}

template<size_t MAX>
void runTests(const std::bitset<MAX>* pSieve) { 
    cout << "1997: " << isPrimeSieve(1997, *pSieve) << endl;   // prime
    cout << "219: " << isPrimeSieve(219, *pSieve) << endl;    
    cout << "509: " << isPrimeSieve(509, *pSieve) << endl;     // prime    
    cout << "1501: " << isPrimeSieve(1501, *pSieve) << endl;
    cout << "977: " << isPrimeSieve(977, *pSieve) << endl;     // prime
    cout << "997: " << isPrimeSieve(997, *pSieve) << endl;     // prime
    cout << "55733: " << isPrimeSieve(55733, *pSieve) << endl;     // prime
    cout << "56263: " << isPrimeSieve(56263, *pSieve) << endl;     // prime
    cout << "57901: " << isPrimeSieve(57901, *pSieve) << endl;     // prime
    cout << "69807: " << isPrimeSieve(69807, *pSieve) << endl;     
    cout << "69809: " << isPrimeSieve(69809, *pSieve) << endl;     // prime
    cout << "69767: " << isPrimeSieve(69767, *pSieve) << endl;     // prime
    cout << "69779: " << isPrimeSieve(69779, *pSieve) << endl;     // prime
    cout << "69809: " << isPrimeSieve(69809, *pSieve) << endl;     // prime
    cout << "69821: " << isPrimeSieve(69821, *pSieve) << endl;     // prime
    cout << "69827: " << isPrimeSieve(69827, *pSieve) << endl;     // prime
    cout << "69829: " << isPrimeSieve(69829, *pSieve) << endl;     // prime
    cout << "69833: " << isPrimeSieve(69833, *pSieve) << endl;     // prime
    cout << "69847: " << isPrimeSieve(69847, *pSieve) << endl;     // prime
    cout << "69857: " << isPrimeSieve(69857, *pSieve) << endl;     // prime
    cout << "69859: " << isPrimeSieve(69859, *pSieve) << endl;     // prime
    cout << "69877: " << isPrimeSieve(69877, *pSieve) << endl;     // prime
    cout << "69899: " << isPrimeSieve(69899, *pSieve) << endl;     // prime
    cout << "69911: " << isPrimeSieve(69911, *pSieve) << endl;     // prime
    cout << "69929: " << isPrimeSieve(69929, *pSieve) << endl;     // prime
    cout << "69931: " << isPrimeSieve(69931, *pSieve) << endl;     // prime
    cout << "69941: " << isPrimeSieve(69941, *pSieve) << endl;     // prime
    cout << "69959: " << isPrimeSieve(69959, *pSieve) << endl;     // prime
    cout << "69991: " << isPrimeSieve(69991, *pSieve) << endl;     // prime
    cout << "69997: " << isPrimeSieve(69997, *pSieve) << endl;     // prime    
}

template<typename IntegralType> 
size_t digitCount(IntegralType v) {
    size_t c = 1;
    while((v /= 10) > 0) c++;
    return c;
}

template<typename IntegralType> 
size_t pow(IntegralType n, size_t p) {
    IntegralType r = 1;
    for (size_t i = 0; i < p; i++, r *= n);
    return r;
}

int main(int argc, char** argv) {
    // build_sieve();
    /*
    cout << boolalpha;
    cout << 1997 << ':' << is_prime_sieve(1997) << endl;
    cout << 31 << ':' << is_prime_sieve(31) << endl;    
    cout << 1999 << ':' << is_prime_sieve(1999) << endl;        
    cout << 2001 << ':' << is_prime_sieve(2001) << endl;
    
    long long primesSum = 0;
    for (size_t i = 2; i < 2000000; i++) { 
        if (is_prime_sieve(i)) {
            primesSum += i;
            cout << "suming " << i << ", so far " << primesSum << endl;            
        }
    }
    cout << primesSum << endl;
    */
    
    /*
    const size_t MAX = 9000000;

    clock_t time = clock();
    std::bitset<MAX>* pSieve = sieveOfAtkin<MAX>();
    time = clock() - time;
    cout << (static_cast<double>(time) / CLOCKS_PER_SEC) << endl;

    runTests<MAX>(pSieve);
    
    delete pSieve;
    
    cout << endl << endl;
    //cout << is_prime(91) << endl;
    time = clock();
    pSieve = sieveOfErathostenes<MAX>();
    time = clock() - time;
    cout << (static_cast<double>(time) / CLOCKS_PER_SEC) << endl;

    runTests<MAX>(pSieve);
    
    delete pSieve;    
    */ 

    const size_t MAX = 90000000;
    std::bitset<MAX>* pSieve = sieveOfAtkin<MAX>();    
    std::cout << "sieve built up" << std::endl;
    size_t truncatablePrimesCount = 0;
    
    vector<size_t> truncatablePrimes;
    
    for (size_t n = 11; n < MAX; n++) { 
        if (isPrimeSieve(n, *pSieve)) { 
            size_t digits = digitCount(n);

            // from right to left
            size_t m = n;
            bool truncatable = true;
            for (size_t i = 1; i < digits; i++) { 
                m /= 10;
                if (!isPrimeSieve(m, *pSieve)) {
                    truncatable = false;
                    break;
                }
            }
            
            if (!truncatable) continue;
            
            // from left to right
            m = n;
            for (size_t i = 1; i < digits; i++) { 
                m = n % pow(10, i);
                if (!isPrimeSieve(m, *pSieve)) {
                    truncatable = false;
                    break;
                }                
            }
            
            if (truncatable) { 
                std::cout << "found a truncatable prime: " << n << std::endl;
                truncatablePrimes.push_back(n);
                truncatablePrimesCount++;
                if (truncatablePrimesCount == 11) break;
            }
        }
    }
    std::cout << std::accumulate(truncatablePrimes.begin(), truncatablePrimes.end(), 0) << std::endl;
    
    return 0;
}
