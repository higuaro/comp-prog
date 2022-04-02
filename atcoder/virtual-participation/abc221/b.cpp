#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t; cin >> s >> t;
  for (int i = 0; i < s.size() - 1; i++) {
    swap(s[i], s[i + 1]);
    if (s == t) {
      cout << "Yes" << endl;
      return 0;
    }
    swap(s[i], s[i + 1]);
  }
  cout << (s == t ? "Yes" : "No") << endl;
  return 0;
}
