#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> ns(n, 0);
    for (auto& ni : ns) cin >> ni;
    if (ns.size() == 1) {
      cout << "YES\n"; continue; 
    }
    if (ns[1] - ns[0] > 3) {
      cout << "NO\n"; continue;
    }
    bool pushed = false;
    if (ns[1] - ns[0] > 1) {
      ns[0]++;
      pushed = true;
    }
    bool valid = true;
    for (int i = 1; i < n; i++) {
      int d = ns[i] - ns[i - 1];
      if (d > 3) {
        valid = false;
        break;
      } else if (d == 3) {
        if (pushed) {
          valid = false; 
          break;
        } else {
          pushed = true;
          ns[i]--;
        }
      } else if (d == 2) {
        ns[i]--;
      }
    }
    cout << (valid ? "YES" : "NO") << endl;
  }
  return 0;
}
