#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ll;
inline ll gcd(ll a, ll b, ll c) {
  return __gcd(a, __gcd(b, c));
}
inline ll lcm(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}
inline ll lcm(ll a, ll b, ll c) {
  return lcm(a, lcm(b, c));
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n; cin >> n;
  ll max = numeric_limits<ll>::min();
  if (n <= 2) max = n;
  else {
    ll base = n > 30 ? n - 10 : 1;
    for (ll i = base; i <= n; i++) {
      for (ll j = base; j <= n; j++) {
        for (ll k = base; k <= n; k++) {
          ll tmp = lcm(i, j, k);
          if (tmp > max) max = tmp;
        }
      }
    }
  }
  cout << max << endl;
  return 0;
}

