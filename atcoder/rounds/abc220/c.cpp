#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
int main() {
  int n; cin >> n;
  ll sa = 0;
  vector<ll> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sa += a[i];
  }
  ll x; cin >> x;
  ll k = (x / sa) * static_cast<ll>(a.size());
  ll r = x % sa;
  int i = 0;
  while (r >= 0 && i < n) {
    r -= a[i++];
    k++;
  }
  cout << k << endl;
  return 0;
}
