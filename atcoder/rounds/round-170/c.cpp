#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n; cin >> x >> n;
  set<int> p;
  for (int i = 0; i < n; i++) {
    int pi; cin >> pi;
    p.insert(pi);
  }
  int m1 = numeric_limits<int>::max();
  int m2 = numeric_limits<int>::min();
  for (int k = 0; k <= 100; k++) {
    if (!p.count(x + k))
      m1 = min(m1, k);
    if (!p.count(x - k))
      m2 = max(m2, -k);
  }
  cout << x + (m1 >= abs(m2) ? m2 : m1) << endl;
  return 0;
}
