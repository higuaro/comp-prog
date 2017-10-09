#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef unsigned long long ullong;

inline char digitToChar(size_t d, bool uppercase = true) {
    return d >= 10 ? d - 10 + (uppercase ? 'A' : 'a') : d + '0';
}

inline char charToDigit(char d, bool uppercase = true) {
    return d <= '9' ? d - '0' : (uppercase ? d - 'A' : d - 'a') + 10;
}

template<typename IntegralType> 
ullong pow(IntegralType n, size_t p) {
    IntegralType r = 1;
    for (size_t i = 0; i < p; i++, r *= n);
    return r;
}

string toBase(long long n, size_t b) {
    string r;
    long long B = b;
    do {
        r += digitToChar(n % B);
    } while ((n /= B) >= B);
    if (n)
        r += digitToChar(n);
    reverse(r.begin(), r.end());
    return r;
}

ullong evaluateBase10(const string& number, const size_t numberBase) {
    size_t len = number.size();
    ullong res = 0L;
    for (size_t i = 0; i < len; ++i) {
        if (number[len - 1 - i] == '-') continue; 
        size_t d = charToDigit(number[len - 1 - i]);
        if (d >= numberBase) return -1;
        res += d * pow(numberBase, i);
    }
    return res;
}

bool isNegative(const string& number) {
    return number[0] == '-';
}

int main() {
#ifndef ONLINE_JUDGE
    ifstream fis("TheBasesAreLoaded.in");
    cin.rdbuf(fis.rdbuf());
#endif

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        
        size_t base1, base2;
        string number;
        
        while (iss >> base1 >> base2 >> number) {
            long long base10 = evaluateBase10(number, base1);
            if (base10 < 0) { 
                cout << number << " is an illegal base " << base1 << " number" << endl; 
            } else {
                string res = toBase(base10, base2);
                if (isNegative(number)) res = '-' + res;
                cout << number << " base " << base1 << " = " << res << " base " << base2 << endl;
            }
        }
    }
    
    return 0;
}

