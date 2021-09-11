#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> factors(uint64_t n) {
  vector<pair<int, int>> f;
  int k = 0;
  const int L = sqrt(n);
  while (!(n % 2)) {
  //    cout << 2 << endl;
    k++;
    n /= 2;
  }
  if (k) f.push_back({2, k});
  for (int d = 3; d <= L; d += 2) {
    int k = 0;
    while (!(n % d)) {
   //   cout << d << endl;
      k++;
      n /= d;
    }
    if (k) f.push_back({d, k});
  }
  if (f.empty()) f.push_back({n, 1});
  return f;
}
int main() {
  uint64_t n; cin >> n;
  if (n) {
    cout << 2 << endl;
    return 0;
  }
  auto f = factors(n);
  uint64_t total = 1LL;
  for (auto [p, k] : f) {
    cout << p << ',' << k << endl;
    if (p & 1)
      total *= (k + 1);
  }
  cout << 2 * total << endl;
  return 0;
}
