#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_set>
using namespace std;
typedef int64_t ll;
const ll oo = numeric_limits<ll>::max();
ll cost(const int n, const vector<ll>& p, const vector<ll>& s, int i) {
  ll sl = i > 0 ? s[i - 1] : 0;
  ll sr = i < n - 1 ? s[n - 1] - s[i] : 0;
  ll il = p[i] * (i > 0 ? i - 1 : 0);
  ll ir = p[i] * (i < n - 1 ? n - i : 0);
  return abs(sl - il) + abs(sr - ir);
}
int main() {
  int n; cin >> n;
  vector<ll> p(n, 0), sum(n, 0);
  for (auto& pi : p) cin >> pi;
  sort(begin(p), end(p));
  partial_sum(begin(p), end(p), begin(sum));

  unordered_set<ll> seen;
  ll best_cost = oo, best_p = 0;
  for (int i = 0; i < n; i++) {
    if (seen.count(p[i])) continue;
    ll c = cost(n, p, sum, i);
    if (c < best_cost) {
      best_cost = c;
      best_p =p[i];
    }
    seen.insert(p[i]);
  }
  cout << best_p << '\n';
  return 0;
}
