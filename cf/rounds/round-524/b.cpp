#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll s(ll n) {
  if (!n) return 0;
  if (n == 1) return -1;
  if (n == 2) return 1;
  ll k = n / 2;
  ll sum_even = k * (k + 1);
  ll sum = (n * (n + 1)) / 2;
  return -sum + 2 * sum_even;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    cout << (s(r) - s(l - 1)) << endl;
  }
  return 0;
}
