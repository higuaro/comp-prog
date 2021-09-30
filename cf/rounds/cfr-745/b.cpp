#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    uint64_t n, m, k; cin >> n >> m >> k;
    uint64_t m_min = n - 1;
    uint64_t m_max = n * (n - 1) / 2; 
    if (m < m_min || m_max < m) {
      cout << "NO" << endl;
    } else if (m > n + 1 && k >= 2) {
      cout << "YES" << endl;
    } else if (k - 1 <= 2 && m) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
