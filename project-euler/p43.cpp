#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <numeric>
uint64_t toInt64(const std::string& s) {
    uint64_t n = 0;
    for (int i = static_cast<int>(s.size()) - 1, b = 1; i >= 0; i--, b *= 10) {
        n += static_cast<uint64_t>(s[i] - '0') * b;
    }
    return n;
}
int main() {
    std::string n("0123456789");
    uint64_t total = 0;
    size_t primes[] = { 2, 3, 5, 7, 11, 13, 17 };
    while (std::next_permutation(n.begin(), n.end())) { 
        bool found = true;
        for (size_t i = 0; i < 7; i++) {
            std::string v(n.substr(1 + i, 3));
            size_t d = static_cast<size_t>(toInt64(v));
            if (d % primes[i] != 0) { 
                found = false;
                break;
            }
        }
        if (found) {
            std::cout << n << std::endl;
            total += toInt64(n);
        }
    }
    
    std::cout << "total = " << total << std::endl;
    return 0;
}
