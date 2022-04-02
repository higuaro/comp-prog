#include <bits/stdc++.h>
using namespace std;
uint64_t oo = numeric_limits<uint64_t>::max();
array<uint64_t, static_cast<int>(1e5)> memo;
uint64_t solve(const vector<int>& b, int ci) {
  if (memo[ci] != oo) return memo[ci];
  int n = b.size();
  uint64_t m = 0;
  for (int i = ci + 1; i < n; i++) {
    int db = b[i] - b[ci];
    if ((i - ci) == db) {
      m = max(b[i] + solve(b, i), m);
    }
  }
  memo[ci] = m;
  return m;
}

int main() {
  int n; cin >> n;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    b.push_back(t);
  }
  if (b.size() == 1) {
    cout << b[0] << endl;
    return 0;
  }
  memo.fill(oo);
  uint64_t m = 0;
  for (int i = 0; i < n; i++) {
    m = max(b[i] + solve(b, i), m);
  }
  cout << m << endl;

  return 0;
}
