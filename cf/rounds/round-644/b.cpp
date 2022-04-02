#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> s;
    for (int i = 0; i < n; i++) {
      int si; cin >> si;
      s.push_back(si);
    }
    sort(begin(s), end(s));
    int m = numeric_limits<int>::max();
    for (int i = 1; i < n; i++) {
      int d = s[i] - s[i - 1];
      m = min(m, d);
    }
    cout << m << endl;
  }
  return 0;
}
