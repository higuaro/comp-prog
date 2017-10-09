#include <cstdlib>
#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

typedef unsigned int uint; 
typedef list< pair<uint, uint> > listOfPair;

void buildErathostenesSieve(bool* sieve, const int N) {
    memset(sieve, true, sizeof(bool) * N);
    for (int n = 4; n < N; n += 2) sieve[n] = false;
    for (int n = 3; n < N; n += 2)
        for (int i = n * n; i < N; i += n)
             sieve[i] = false;
}

list<uint> buildPrimeList(const bool* const sieve, const int N) {
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

string getStringRepr(const listOfPair& factors) { 
    listOfPair::const_iterator ite = factors.begin();
    listOfPair::const_iterator end = factors.end();
    stringstream str; 
    for (; ite != end; ++ite) { 
        str << (*ite).first << '^' << (*ite).second << "x";
    }
    return str.str();
}

template<class T> struct multiplyFactors : public unary_function<T, void> {
    const uint factor;
    multiplyFactors(const uint factor) : factor(factor) {}
    void operator() (T& x) { x.second *= factor; }
};

template<class T> struct printPrimeFactors : public unary_function<T, void> {
    ostream& out;
    printPrimeFactors(ostream& out) : out(out) {}
    void operator() (T x) { cout << x.first << '^' << x.second << "x"; }
};

int main(int argc, char** argv) {
    const int N = 10000;
    bool sieve[N];
    buildErathostenesSieve(sieve, N);
    list<uint> primes = buildPrimeList(sieve, N);

    map<string, bool> numbers;

    const uint LIMIT = 100;
    for (uint a = 2; a <= LIMIT; a++) { 
        for (uint b = 2; b <= LIMIT; b++) {         
            listOfPair factors = getPrimeFactors(a, primes);
            
            for_each(factors.begin(), factors.end(), multiplyFactors< pair<uint, uint> >(b)); 
            string str = getStringRepr(factors);
            if (numbers.count(str) == 0)
                numbers[str] = true;
        }
    }

    cout << numbers.size() << endl;
    return 0;
}

