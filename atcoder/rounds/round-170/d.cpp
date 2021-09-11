#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> factors(int n) {
  vector<pair<int, int>> f;
  int p = 2;
  int count = 0;
  while (n && !(n % p)) {
    count++; n /= p;
  }
  if (count) f.emplace_back(2, count);
  for (p = 3; p <= sqrt(n); p += 2) {
    count = 0;
    while (n && !(n % p)) {
      count++; n /= p;
    }
    if (count) f.emplace_back(p, count);
  }
  if (n) f.emplace_back(n, 1);
  return f;
}
int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(begin(a), end(a));

  unordered_map<int, int> seen;
  int total = 0;
  for (int i = 0; i < n; i++) {
    int k = a[i];
    if (seen.count(k)) continue;
    auto f = factors(k);
cout << "factors " << k << ": ";
for (auto [p, c] : f) cout << '(' << p << ',' << c << "),"; cout << endl;
    bool factor_seen = false;
    for (auto [p, c] : f) {
      if (seen.count(p) && seen[p] >= c) {
        factor_seen = true;
      } else {
        seen[p] = c;
      }
    }
    if (!factor_seen) total++;
  }
  cout << total << endl;
  return 0;
}
