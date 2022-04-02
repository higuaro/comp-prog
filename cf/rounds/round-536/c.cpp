#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
inline uint64_t sqr(uint64_t k) { return k * k; }
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  vector<int> ns;
  int k = n;
  while (k--) {
    int t; cin >> t;
    ns.push_back(t);
  }

  sort(begin(ns), end(ns));
  uint64_t t = 0;
  for (int i = 0; i < (n >> 1); i++)
    t += sqr(ns[i] + ns[n - i - 1]);
  cout << t << std::endl;
  return 0;
}
