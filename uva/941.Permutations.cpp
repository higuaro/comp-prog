#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <limits>
#include <iomanip>
#include <cstdint>
/*
std::list<size_t> getFactoradic2(uint64_t n) {
    std::list<size_t> res;
    uint64_t k = 1;
    while ((n / k) != 0) {
        res.push_back(n % k); 
        n /= k++;
    }
    res.push_back(n);     
    res.reverse();
    return res;
}
*/

std::list<size_t> getFactoradic(uint64_t n) {
    const std::vector<uint64_t> factos = {1LL, 2LL, 6LL, 24LL, 120LL, 720LL, 5040LL, 40320LL, 362880LL, 3628800LL, 39916800LL, 479001600LL, 6227020800LL, 87178291200LL, 1307674368000LL, 20922789888000LL, 355687428096000LL, 6402373705728000LL, 121645100408832000LL, 2432902008176640000LL};    
    std::list<size_t> res; 
    if (n == 0) return res;
    size_t i = 0;
    for (; i < factos.size(); ++i) if (factos[i] > n) break;
    while (--i > 0) {
        res.push_back(n / factos[i]); n %= factos[i];
    }
    res.push_back(n); res.push_back(0);
    return res;
}

std::string getPermutation(uint64_t index, const std::string& alphabet) {
    std::list<size_t> factoradic = getFactoradic(index);
    std::string copy(alphabet);

    if (copy.size() > factoradic.size())
        factoradic.insert(factoradic.begin(), copy.size() - factoradic.size(), 0);

    std::string res;
    for (size_t index : factoradic) {
        typename std::string::iterator ite = copy.begin();
        std::advance(ite, index);
        res += *ite;
        copy.erase(ite);        
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("Permutations.in");
    std::cin.rdbuf(fis.rdbuf());
#endif
    int nCases = 0;
    std::cin >> nCases; 

    while (nCases--) {
        std::string alphabet;
        uint64_t numPermutation;
        std::cin >> alphabet;
        std::cin >> numPermutation;
        std::sort(alphabet.begin(), alphabet.end());
        std::cout << getPermutation(numPermutation, alphabet) << std::endl;
    }
    return 0;
}
