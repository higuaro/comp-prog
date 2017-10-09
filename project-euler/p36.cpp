#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>

typedef unsigned int uint; 

using namespace std;

/**
 * Counts the 1's in the binary representation of the number  
 */
uint ones32(uint x) {
    x -= (x >> 1) & 0x55555555;
    x = ((x >> 2) & 0x33333333) + (x & 0x33333333);
    x = ((x >> 4) + x) & 0x0f0f0f0f;
    x += (x >> 8);
    x += (x >> 16);
    return x & 0x0000003f;
}

/**
 * Returns the integer part of the log2 of n  
 */
uint floor_log2(const unsigned int n) {
    uint x = n;
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return ones32(x >> 1);
}

string toBinaryString(const uint n) { 
    uint numBits = floor_log2(n) + 1;
    char* str = new char[numBits];
    memset(str, 0, numBits);
    uint a = n, index = numBits - 1;
    while (a > 1) { 
        str[index--] = (a % 2) + '0'; 
        a /= 2;
    }
    str[0] = a + '0';
    string res(str); 
    delete[] str;
    return res;
}

bool isPalindrome(const string& seq) {
    size_t size = seq.size();
    size_t middle = size / 2;
    for (size_t i = 0; i < middle; i++) 
        if (seq[i] != seq[size - i - 1]) return false;
    return true;
}

int main(int argc, char** argv) {
    const uint LIMIT = 1000000;
    unsigned long long sum = 0;
    for (uint i = 1; i < LIMIT; i++) { 
        stringstream s;
        s << i;
        if (isPalindrome(s.str()) && isPalindrome(toBinaryString(i))) 
            sum += i;
    }  
    cout << sum << endl;
    return 0;
}