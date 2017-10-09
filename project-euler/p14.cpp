#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

typedef vector< int > vint;
// typedef unsigned long uint;


const int kNumIters = 1000000;
const int kMemoSize = kNumIters * 100;

uint memo[kMemoSize];

int main() { 
	memset(memo, 0, sizeof(memo) / sizeof(uint));
	memo[1] = 1;
    memo[2] = 2;
// for (int i = 0; i < kMemoSize; i++) memo[i] = 0;

    uint max = 0, cameFrom = 0;
    for (int i = 3; i <= kNumIters; i++) { 
       uint n = i;
       uint count = 0;
// cout << n;
       while (n != 1) { 
           if (n < kMemoSize && n > 0 && memo[n]) { 
// cout << "+memo{" << n << "} = " << memo[n] << endl;
               count += memo[n];
               break;
           } else 
               count++;
           if (n & 1)
               n = 3 * n + 1;
           else
               n >>= 1;

// cout << "->" << n;
       }
// cout << " count: " << count << endl << endl;
       memo[i] = count;
       
       if (count > max) { 
          max = count;
          cameFrom = i;
       }
    }
cout << "max = " << cameFrom << ", seq count = " << max << endl;
}
