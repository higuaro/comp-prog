#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, t; cin >> T; t = T;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    int nn = 1 << n;
    set<string> ss;
    for (int k = 0; k < nn; k++) {
      string si;
      for (int i = 0; i < n; i++) {
        si += s[i];
        if ((k >> i) & 1) si += s[i];
      }
      ss.insert(si);
    }
    cout << "Case #" << (T - t) << ": " << *ss.begin() << '\n';
  }
  return 0;
}
