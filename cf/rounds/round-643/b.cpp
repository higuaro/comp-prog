#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> e;
    for (int i = 0; i < n; i++) {
      int ei; cin >> ei;
      e.push_back(ei);
    }
    sort(begin(e), end(e));

    int g = 0, p = 1;
    int m = e[0];
    for (int i = 1; i < n; i++) {
      int ei = e[i];
      if (p == m) {
        g++;
        m = ei;
        p = 0;
      } else {
        m = max(m, ei);
      }
      p++;
    }
    if (p == m) g++;
    cout << g << endl;
  }
  return 0;
}
