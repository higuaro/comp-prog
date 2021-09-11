#include <bits/stdc++.h>
using namespace std;
const int oo = 99999999;
//unordered_map<uint64_t, unordered_map<uint64_t, uint64_t>> memo[20000];
unordered_map<int, unordered_map<uint64_t, unordered_map<uint64_t, uint64_t>>> memo;
int solve(const vector<pair<int, int>>& t, int i, uint64_t va, uint64_t vb) {
  if (memo.count(i)) {
    auto& dpva = memo[i];
    if (dpva.count(va)) {
      auto& dpvb = dpva[va];
      if (dpvb.count(vb)) 
        return dpvb[vb];
    }
  }

  if (vb > va) return 0;
  if (i < 0) return oo;
  auto [a, b] = t[i];

  return memo[i][va][vb] = min(
      1 + solve(t, i - 1, va - a, vb + a + b),
      solve(t, i - 1, va, vb));
}
int main() {
  int n; cin >> n;
  vector<pair<int, int>> t;
  uint64_t va = 0;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    t.push_back({a, b});
    va += a;
  }
  sort(begin(t), end(t), 
      [] (const auto& p1, const auto& p2) {
        return p1.first + p1.second < p2.first + p2.second;
      });

  cout << solve(t, n - 1, va, 0ULL) << endl;
  return 0;
}
