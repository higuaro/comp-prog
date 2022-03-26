#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> x(n, 0);
  int pos = 0;
  for (auto& xi : x) {
    cin >> xi;
    pos += xi > 0 ? 1 : 0;
  }
  if (pos <= 1) {
    cout << *max_element(begin(x), end(x)) << endl;
    return 0;
  }
  int64_t sum = 0;
  int64_t si = 0;
  for (int i = 0; i < n; i++) {
    si += x[i];
    si = max(si, static_cast<int64_t>(0));
    sum = max(sum, si);
  }
  cout << sum << '\n';
  return 0;
}
