#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t s, t; cin >> s >> t;
  uint64_t count = 0;
  for (uint64_t a = 0; a <= 100; a++) 
    for (uint64_t b = 0; b <= 100; b++) 
      for (uint64_t c = 0; c <= 100; c++) 
        if (a + b + c <= s && a * b * c <= t) count++;
  cout << count << endl;
}
