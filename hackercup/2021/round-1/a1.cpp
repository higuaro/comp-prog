#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  int T = 1;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int swaps = -1;
    char m = 0;
    for (char c : s) {
      if (c != 'F' && c != m) {
        m = c;
        swaps++;
      }
    }
    cout << "Case #" << T++ << ": " << max(0, swaps) << '\n';
  }
  return 0;
}
