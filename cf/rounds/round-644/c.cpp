#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a;
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++) {
      int ai; cin >> ai;
      if (ai & 1) odds++;
      else evens++;
      a.push_back(ai);
    }
    if (!(odds & 1)) {
      cout << "YES" << endl;
      continue;
    }
    sort(begin(a), end(a));
    bool found_diff = false;
    for (int i = 1; i < n; i++) {
      int d = a[i] - a[i - 1];
      if (d == 1) {
        found_diff = true;
        break;
      }
    }
    cout << (found_diff ? "YES" : "NO") << endl;
  }
  return 0;
}
