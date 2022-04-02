#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    vector<pair<int, int>> s;
    string l; cin >> l;
    int n = l.size();
    int prev = static_cast<int>(l[0] - '0');
    int count = 1;
    array<bool, 3> found; found.fill(false);
    found[prev - 1] = true;
    for (int i = 1; i < n; i++) {
      int si = static_cast<int>(l[i] - '0');
      found[si - 1] = true;
      if (si == prev) {
        count++;
      } else {
        s.emplace_back(prev, count);
        prev = si;
        count = 1;
      }
    }
    s.emplace_back(prev, count);

    if (any_of(begin(found), end(found), [](bool f) { return !f; })) {
      cout << 0 << endl;
      continue;
    }

    int m = l.size() + 1;
    n = s.size();
    for (int i = 0; (i + 2) < n; i++) {
      auto [d1, c1] = s[i];
      auto [d2, c2] = s[i + 1];
      auto [d3, c3] = s[i + 2];
      if (d1 != d2 && d2 != d3 && d1 != d3) 
        m = min(m, 2 + c2);
    }
    cout << m << endl;
  }
}
