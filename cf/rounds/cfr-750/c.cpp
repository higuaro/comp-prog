#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int oo = numeric_limits<int>::max();
    int best = oo;
    for (int c = 'a'; c <= 'z'; c++) {
      bool is_pal = true;
      int deleted = 0;
      for (int i = 0, j = n - 1; i < j; ) {
        if (s[i] == s[j]) {
          i++; j--; continue;
        }
        if (s[i] == c) {
          deleted++; i++;
        } else if (s[j] == c) {
          deleted++; j--;
        } else {
          is_pal = false;
          break;
        }
      }
      if (is_pal) best = min(best, deleted);
    }
    cout << (best == oo ? -1 : best) << endl;
  }
  return 0;
}
