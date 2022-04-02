#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
int main() {
  int n, k, x; cin >> n >> k >> x;
  priority_queue<ll> a, multiples_x;
  for (int i = 0; i < n; i++) {
    ll ai; cin >> ai;
    ((ai % x) ? a : multiples_x).push(ai);
  }
  while (!multiples_x.empty() && k) {
    ll v = multiples_x.top(); multiples_x.pop();
    if ((v / x) > k) {
      v = v - x * k;
      k = 0;
      multiples_x.push(v);
    } else {
      k -= (v / x);
    }
  }

  while (!a.empty() && k) {
    ll ai = a.top(); a.pop();
    if ((ai / x) > k) {
      ai = ai - k * x;
      a.push(ai);
      k = 0;
    } else if (!(ai / x)) {
      k--;
    } else {
      ll c = ai / x;
      k -= c;
      ai -= c * x;
      a.push(ai);
    }
  }

  ll sum = 0;
  while (!multiples_x.empty()) { sum += multiples_x.top(); multiples_x.pop(); }
  while (!a.empty()) { sum += a.top(); a.pop(); }
  cout << sum << '\n';
  return 0;
}
