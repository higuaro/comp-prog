#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned int uint;


inline bool is_even(uint n) { 
    return n & 1;
}

int main(int argc, char** argv) {
    
    const uint LIMIT = 10000;
    uint sum_divisors[LIMIT + 1];
    
    sum_divisors[1] = 1;
    sum_divisors[2] = 1;
    
    for (uint n = 3; n <= LIMIT; n++) { 
        uint dn = 1;
        uint d = 0;
        uint start = 0;
        if (is_even(n)) { 
            d = 2;
            start = 3;
        } else {
            d = 1;
            start = 2;
        }
        const uint limit = n / 2;
        for (uint k = start; k <= limit; k += d) 
            if ((n % k) == 0) dn += k; 
        
        sum_divisors[n] = dn;
// printf("d(%d) = %d\n", n, dn); 

    }
    
    uint sum = 0;
    for (uint n = 2; n <= LIMIT; n++) { 
        uint dn = sum_divisors[n];
        if (dn != n && dn <= LIMIT && sum_divisors[dn] == n) { 
            // Amicable pair!
cout << n << "," << dn << endl;
            sum += (n + dn);
            sum_divisors[n] = 0;
            sum_divisors[dn] = 0;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}

