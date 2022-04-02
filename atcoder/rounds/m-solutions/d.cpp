#include <bits/stdc++.h>
using namespace std;
unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;

int solve(const int n, const vector<int>& a, const int d,
          int m, int s) {
  if (d >= n) return m;

  int t = memo[d][m][s];
  if (t) return t;

  int tb = 0;
  int max_buy = m / a[d];
  for (int si = 0; si <= max_buy; si++)
    tb = max(tb, solve(n, a, d + 1, m - si * a[d], s + si));

  int ts = 0;
  for (int si = 0; si <= s; si++) 
    ts = max(ts, solve(n, a, d + 1, m + si * a[d], s - si));

  int r = max(tb, ts);
  memo[d][m][s] = r;
  return r;
}
int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << solve(n, a, 0, 1000, 0) << endl;
  return 0;
}
