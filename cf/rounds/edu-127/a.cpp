#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    int count = 1;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++) {
      char c = s[i];
      if (c != prev) {
        if (count == 1)
          break;
        prev = c;
        count = 1;
      } else count++;
    }
    cout << (count > 1 ? "YES" : "NO") << endl;
  }
  return 0;
}
