#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  string s; cin >> s;
  int l = s.size();
  int t = 0;
  for (int i = l - 1, j = 0; i > j; i--) {
    char ci = s[i];
    if (ci == 'R') {
      for (; j < i; j++) {
        char cj = s[j];
        if (cj == 'W') {
          swap(s[i], s[j]);
          t++;
          break;
        }
      }
    }
  }
  cout << t << endl;
  return 0;
}
