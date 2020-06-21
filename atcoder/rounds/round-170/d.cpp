#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> factors(int n) {
  vector<pair<int, int>> f;
  int p = 2;
  int count = 0;
  while (n && (n % p) == 0) {
    count++;
    n %= p;
  }
  if (count) f.emplace_back(2, count);
  for (p = 3; p <= sqrt(n); p += 2) {
    count = 0;
    while (n && (n % p) == 0) {
      count++;
      n %= p;
    }
    if (count) f.emplace_back(p, count);
  }
  return f;
}
int main() {
  int n; cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    a.push_back(ai);
  }
  sort(begin(a), end(a));

  unordered_map<int, int> seen;
  int total = 0;
  for (int i = 0; i < n; i++) {
    int k = a[i];
    if (seen.count(k)) continue;
    auto f = factors(k);
    if (f.empty()) {
      seen[k] = 1;
      total++;
    } else {
      bool factor_seen = false;
  cout << k << ':' << endl;
      for (auto [p, c] : f) {
cout << p << ' ' << c << endl;

        if (seen.count(p)) {
          if (seen[p] < c) {
            seen[p] = c;
          } else {
            factor_seen = true;
          }
        }
      }
      if (!factor_seen) total++;
    }
  }
  cout << total << endl;
  return 0;
}
