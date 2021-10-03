#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int64_t n, m, k; cin >> n >> m >> k;
    k--;
    uint64_t m_min = n - 1;
    uint64_t m_max = n * (n - 1) / 2;
    if (m < m_min || m_max < m) {
      cout << "NO" << endl;
    } else {
      int diam = m && m == m_max ? 1 : (!m ? 0 : 2);
      cout << (diam < k ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
