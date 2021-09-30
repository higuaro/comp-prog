#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    uint64_t v = 1;
    for (uint64_t k = 3; k <= 2 * n; k++)
      v = ((v * k)) % M;
    cout << v << endl;
  }
  return 0;
}
