#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <bitset>
#include <sstream>

bool isPrime(const size_t n) {
    if (!(n & 1) && n != 2) return false;
    const size_t lim = static_cast<size_t>(sqrt(n));
    for (size_t i = 3; i <= lim; i += 2)
        if ((n % i) == 0) return false;
    return true;
}

int main() {
    const std::string N = "987654321";
    std::string n;
    for (int i = 8; i >= 0; i--) { 
        n = N.substr(8 - i, i + 1);
        do { 
            std::stringstream ss(n);
            long perm;
            ss >> perm;
            if (isPrime(perm)) { 
                std::cout << "The prime is: " << perm << std::endl;
                return 0;
            }
        } while (std::prev_permutation(n.begin(), n.end()));
    }
    return 0;
}
