#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll solve() {
  ll n, x; cin >> n >> x;
  vector<ll> ns(n, 0);
  for (auto& ni : ns) cin >> ni;
  sort(begin(ns), end(ns));
  vector<ll> s(n, 0);
  partial_sum(begin(ns), end(ns), begin(s));
  ll total = 0;
  ll days = 0;
  while (!s.empty()) {
    ll sum = s.back(); s.pop_back();
    sum += days * n;
    ll d = 0;
    if (x >= sum) {
      d = ((x - sum) / n) + 1;
    }
    total += d * n;
    days += d;
    n--;
  }
  return total;
}
int main() {
  int t; cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
