#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t n; cin >> n;
  uint64_t sum = 0; 
  for (int i = 0; i < n - 1; i++) {
    uint64_t v; cin >> v;
    sum += v;
  }
  uint64_t ss = n * (n + 1ULL) / 2ULL; 
  cout << ss - sum << endl;
  return 0;
}
