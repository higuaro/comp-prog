#include <bits/stdc++.h>
using namespace std;
const uint64_t M = 1e9 + 7;
uint64_t pow2(int k) {
  if (!k) return 1;
  if (k == 1) return 2;
  uint64_t r = pow2(k / 2) % M;
  uint64_t r2 = r * r;
  return k & 1 
    ? ((r2 % M) * 2) % M
    : r2 % M;
}
int main() {
  uint64_t n; cin >> n;  
  cout << pow2(n) << endl;
  return 0;
}
