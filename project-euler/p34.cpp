#include <iostream>
typedef long unsigned int ulong;
using namespace std;

size_t getNumDigits(const size_t n) { 
    size_t a = n, count = 0;
    while (a > 0) { 
        a /= 10; count++;
    }
    return count;
}
size_t getDigitAt(const size_t n, const size_t position) {
    ulong div = 1;
    for (size_t i = 0; i < position; i++, div *= 10);
    return (n / div) % 10;
}
 
int main() { 
/*
    const ulong N = 1551887;
    for (size_t i = 0; i < getNumDigits(N); i++) 
        cout << getDigitAt(N, i) << endl;
*/
    ulong facts[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
    const ulong LIMIT = 1000000000;
    const ulong ONE_PERCENT = LIMIT / 100;
    ulong percentCounter = 0;
    size_t percent = 0;
    ulong sum = 0;
    for (ulong n = 10; n < LIMIT; n++) {
        const size_t numDigits = getNumDigits(n);
        ulong sumFactDigits = 0;
        for (size_t i = 0; i < numDigits; i++) {
            size_t digit = getDigitAt(n, i);
            sumFactDigits += facts[digit];
        }
        if (sumFactDigits == n) { 
            sum += n;   
            cout << "Found: " << n << endl;
        }
        
        percentCounter++;
        if (percentCounter == ONE_PERCENT) { 
            percentCounter = 0;
            percent++;
            if ((percent % 2) == 0) 
                cout << percent << "%" << endl; 
        }
    }
    cout << sum << endl;
    return 0;
}
