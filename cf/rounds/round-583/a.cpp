#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> memo;
int solve(int n, const vector<int>& prices) {
  if (!n) return 0;
  if (memo.count(n)) return memo[n];
  int min = n;
  for (int p : prices) {
    int d = n - p;
    if (d < 0) continue;
    int m = solve(d, prices);
    if (m >= 0 && m < min) min = m;
  }
  memo[n] = min;
  return min;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, e; cin >> n >> d >> e;
  vector<int> prices{
    1 * d,  2 * d,  5 * d, 10 * d,  20 * d,  50 * d, 100 * d,
    5 * e, 10 * e, 20 * e, 50 * e, 100 * e, 200 * e
  };
  sort(prices.begin(), prices.end(), greater<int>());

  cout << solve(n, prices) << endl;
  return 0;
}
