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
#include <sstream>
#include <map>

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

std::vector<size_t> getPermutations(const size_t n) {
    std::string p(std::to_string(n));
    
    std::vector<size_t> perms;
    perms.reserve(24);
    perms.push_back(n);

    while (std::next_permutation(p.begin(), p.end())) {
        perms.push_back(std::stoi(p));
    }
    std::sort(perms.begin(), perms.end());
    
    return perms;
}

template<size_t N> std::string analyseSequence(const std::vector<size_t>& seq, std::map<size_t, bool>& checked, const std::bitset<N>& primes) {
    size_t size = seq.size(); 

    std::map<size_t, bool> perms;
    for (auto n : seq) { 
        perms[n] = true;
    }
    for (size_t i = 0; i < size - 2; i++) {
        size_t n = seq[i];
        checked[n] = true;
        if (!primes[n]) continue;
        for (size_t j = i + 1; j < size; j++) { 
            size_t k = seq[j];
            if (!primes[k]) continue;            
            size_t q = k + (k - n);
            if (primes[q] && perms[q]) {
                return std::to_string(n) + std::to_string(k) + std::to_string(q);
            }
        }
    }
    return "";
}

int main() {
    const size_t MAX_PRIMES = 100000;
    std::bitset<MAX_PRIMES> primes;
    fillSieveOfAtkin(primes);
    std::map<size_t, bool> checked;
    
    for (size_t n = 1000; n < 9999; n++) { 
        if (!primes[n] || checked[n]) continue;
        
        std::string sNumber = std::to_string(n);
        std::sort(sNumber.begin(), sNumber.end());
        int k = std::stoi(sNumber);
        if (checked[k]) continue;
        
        std::vector<size_t> perms = getPermutations(k);
        
        std::string res = analyseSequence(perms, checked, primes);
        if (res != "" && res != "148748178147") {
            std::cout << "Found: " << res << std::endl;
            return 0;
        }
    } 
    return 0;
}
