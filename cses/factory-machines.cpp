#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll eval(const vector<ll>& k, ll ti, ll target) {
  ll p = 0;
  for (auto ki : k) {
    p += ti / ki;
    if (p > target) return p;
  }
  return p;
}
int main() {
  ll n, products; cin >> n >> products;
  vector<ll> k(n, 0);
  for (auto& ki : k) cin >> ki;
  ll lo = 1, hi = 1e18;
  while (lo <= hi) {
    ll ti = (hi + lo) / 2;
    if (eval(k, ti, products) < products)
      lo = ti + 1;
    else
      hi = ti - 1;
  }
  cout << lo << endl;
  return 0;
}
