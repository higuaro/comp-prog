#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
vector<pair<int, int>> factors(int n) {
  if (n == 1) return {{1, 1}};
  vector<pair<int, int>> f;
  int c = 0;
  while (!(n % 2)) {
    c++; n /= 2;
  }
  if (c) f.push_back({2, c});
  for (int k = 3; k <= n; k += 2) {
    c = 0;
    while (!(n % k)) {
      c++; n /= k;
    }
    if (c) f.push_back({k, c});
  }
  return f;
}
uint64_t solve(const vector<pair<int, vector<pair<int, int>>>>& a, const int n,
    int i = 0) {
  return 0;
}
int main() {
  int n; cin >> n;
  vector<pair<int, vector<pair<int, int>>>> a;
  gp_hash_table<int, vector<pair<int, int>>> factors_cache;
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    if (factors_cache.find(ai) != factors_cache.end())
      a.push_back({ai, factors_cache[ai]});
    else 
      a.push_back({ai, factors_cache[ai] = factors(ai)});
  }
  factors_cache.clear();
  sort(begin(a), end(a), greater<>());
  uint64_t m = 0;
  for (int i = 0; i < n; i++) {
    m = max(m, solve(a, i));
  }
  cout << m << endl;
  return 0;
}
