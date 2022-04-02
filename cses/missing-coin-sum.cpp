#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
int main() {
  int n; cin >> n;
  vector<ll> x(n, 0);
  for (auto& xi : x) cin >> xi;
  sort(begin(x), end(x));
  if (x[0] != 1) {
    cout << "1\n";
    return 0;
  }

  ll s = 1;
  for (int i = 1; i < n; i++) {
    if (x[i] > s + 1) 
      break;
    s += x[i];
  }

  cout << s + 1 << '\n';
  return 0;
}
