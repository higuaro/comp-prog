#include <iostream>
// typedef unsigned long long ulong;
int main() { 
    const ulong SIZE = 99;
    ulong c[SIZE][SIZE];
    for (ulong i = 0; i < SIZE; i++) {
        c[i][0] = i + 2; c[0][i] = i + 2;
    }
    int total = 0;
    for (ulong i = 1; i < SIZE; i++)
        for (ulong j = 1; j < SIZE - i; j++) {
            c[i][j] = c[i - 1][j] + c[i][j - 1];
            if (c[i][j] > 1000000) { 
                total += SIZE - i - j; break;
            }   
        }
    std::cout << total << std::endl;
    return 0;
}
