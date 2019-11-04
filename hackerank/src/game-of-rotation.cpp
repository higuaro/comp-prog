#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> a;
  ll sum = 0;
  ll pmean = 0;
  for (int i = 1; i <= n; i++) {
    ll v; cin >> v;
    a.push_back(v);
    sum += v;
    pmean += static_cast<int>(i) * v;
  }

  ll max = pmean;
  for (int i = 0; i < n; i++) {
    pmean = pmean + sum - n * a[n - 1 - i];
    if (pmean > max) max = pmean;
  }
  cout << max << endl;
  return 0;
}
