#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
vector<uint8_t> a, b;
ll memo[20][2][2][2];
ll p(ll n) {
  if (!n) return 0;
  ll r = 1;
  while (n) {
    r *= n % 10;
    n /= 10;
  }
  return r;
}
ll pow10(int k) {
  ll r = 1;
  for (int i = 0; i < k; i++) r *= 10;
  return r;
}
ll solve(int i = 0, int l0 = true, int gta = false, int ltb = false) {
  if (i >= b.size()) return 0;
  if (memo[i][l0][gta][ltb] != -1) return memo[i][l0][gta][ltb];
  int min_d = gta ? 1 : a[i];
  int max_d = ltb ? 9 : b[i];
  l0 = l0 && !min_d;
  ll max_p = -1;
  ll n = 0;
  for (int d = min_d; d <= max_d; d++) {
    int gtai = gta || d > a[i];
    int ltbi = ltb || d < b[i];
    ll nn = pow10(b.size() - i - 1) * d + solve(i + 1, l0, gtai, ltbi);
    ll prod = !l0 && !d ? 0 : p(nn);
    if (prod > max_p) {
      n = nn;
      max_p = prod;
    }
  }
  return memo[i][l0][gta][ltb] = n;
}

int main() {
  ll la, lb; cin >> la >> lb;
  while (lb) {
    b.push_back(lb % 10);
    lb /= 10;
  }
  reverse(begin(b), end(b));
  while (la) {
    a.push_back(la % 10);
    la /= 10;
  }
  for (int i = 0; i < b.size() - a.size(); i++) 
    a.push_back(0);
  reverse(begin(a), end(a));
  memset(memo, -1, sizeof memo);

  cout << solve() << endl;
  return 0;
}
