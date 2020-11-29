#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> h(n, 0);
    unordered_map<int, int> hc;
    for (int i = 0; i < n; i++) {
      int colour; cin >> colour;
      h[i] = colour;
      hc[colour]++;
    }
    if (hc.size() == 1) {
      cout << 0 << endl;
      continue;
    }
    int min_days = numeric_limits<int>::max();
    bool first_colour = true;
    for (int c = 1; c <= 100; c++) {
      int days = 0;
      if (!hc.count(c)) continue;
      for (int i = 0; i < n; i++) {
        if (h[i] != c) {
          days++;
          if (!first_colour && days > min_days) break;
          i += k - 1;
        }
      }
      min_days = min(min_days, days);
      first_colour = false;
    }
    cout << min_days << endl;
  }
  return 0;
}
