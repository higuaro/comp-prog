#include <bits/stdc++.h>
using namespace std;
uint64_t sum(const uint64_t n) {
  return (n * (n + 1ULL)) / 2ULL;
}
int main() {
  int t; cin >> t;
  while (t--) {
    uint64_t n, r; cin >> n >> r;
    cout << (n > r ? sum(r) : sum(n - 1ULL) + 1ULL) << endl;
  }
  return 0;
}
