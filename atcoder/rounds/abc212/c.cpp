#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  vector<int> a(n, 0), b(m, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i]; 
  vector<pair<int, int>> c;
  for (int i = 0; i < n; i++) c.push_back({a[i], 0});
  for (int i = 0; i < m; i++) c.push_back({b[i], 1});
  sort(begin(c), end(c), [](const pair<int, bool>& p1, const pair<int, bool>& p2) {
    if (p1.first == p2.first)
      return p1.second < p2.second;
    return p1.first < p2.first;
  });

  const int oo = 1e9 + 1000;
  int min_d = oo;
  for (int i = 0; i < n + m - 1; i++) {
    auto ci = c[i];
    auto cii = c[i + 1];
    int is_ab_or_ba = ci.second ^ cii.second;
    if (is_ab_or_ba)
      min_d = min(min_d, abs(ci.first - cii.first));
  }
  cout << min_d << endl;
  return 0;
}
