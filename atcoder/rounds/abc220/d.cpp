#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int M = 998244353;
int memo[static_cast<int>(1e5) + 1][10];
int calc(const vector<uint8_t>& a, int i, uint8_t di) {
  if (i > a.size()) return 0;
  if (i == a.size()) return 1;
  if (memo[i][di] != -1) return memo[i][di];
  int sum = calc(a, i + 1, (a[i] + a[i + 1]) % 10) % M;
  int prod = calc(a, i + 1, (a[i] * a[i + 1]) % 10) % M;
  return memo[i][di] = (sum + prod) % M;
}
void solve(const vector<uint8_t>& a) {

  memo[0][0] = (calc(a, 2, (a[0] + a[1]) % 10) 
      + calc(a, 2, (a[0] * a[1]) % 10)) % M;
}
int main() {
  int n; cin >> n;
  vector<uint8_t> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(memo, -1, sizeof memo);
  solve(a);
  int digits[10];
  memset(digits, 0, sizeof digits);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      digits[j] = (digits[j] + max(0, memo[i][j])) % M;
  for (int i = 0; i < 10; i++)
    cout << digits[i] << endl;
  return 0;
}
