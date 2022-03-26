#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t n; cin >> n;
  while (n != 1) {
    cout << n << ' ';
    if (n & 1) n = 3ULL * n + 1ULL;
    else n /= 2ULL;
  }
  cout << "1\n";
  return 0;
}
