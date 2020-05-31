#include <bits/stdc++.h>
using namespace std;

vector<pair<uint64_t, int>> factors(uint64_t n) {
  vector<pair<uint64_t, int>> f;
  int count = 0;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  if (count)
    f.push_back({2, count});
  for (uint64_t k = 3; k <= sqrt(n); k += 2) {
    count = 0;
    while (n % k == 0) {
      count++;
      n /= k;
    }
    if (count)
      f.push_back({k, count});
  }

  if (n > 2)
    f.push_back({n, 1});
  return f;
}
uint64_t ipow(uint64_t n, int k) {
  uint64_t r = 1ULL;
  for (int i = 0; i < k; i++)
    r *= n;
  return r;
}
int main() {
  uint64_t n; cin >> n;
  int total = 0;
  unordered_set<uint64_t> zs;

  for (auto [p, c] : factors(n)) {
    for (int k = 1; k <= c; k++) {
      uint64_t z = ipow(p, k);
      if (!zs.count(z) && n % z == 0) {
        n /= z;
        total++;
        zs.insert(z);
      }
    }
  }
  cout << total << endl;
  return 0;
}
