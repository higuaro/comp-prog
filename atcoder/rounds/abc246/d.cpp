#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll ff(ll a, ll b) {
  return a * a * a + a * a * b + a * b * b + b * b * b;
}
ll f(ll k) {
  ll l = 1, r = k;
  ll best = ff(l, r);
  while (l <= r) {
    ll m = l + (r - l) / 2;
    ll res = ff(l, m);
    if (res < best) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return best;
}
int main() {
  ll n; cin >> n;
  ll l = 1, r = 2000000;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    ll res = f(m);
    if (res > n) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << f(l) << endl;
  return 0;
}
