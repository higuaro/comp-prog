#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    bool leading_one = s[0] == '1';

    string sol = s;
    if (leading_one) {
      for (int i = 0; i < n; i++) 
        sol[i] = s[i] != '9' ? '9' - s[i] + '0' : '0';
    } else {
      int carry = 0;
      for (int i = n - 1; i >= 0; i--) {
        char c = s[i]; 
        int d = c - '0' + carry;
        carry = 0;
        if (d != 1) {
          int dd = d ? 11 - d : 1;
          sol[i] = '0' + (dd % 10);
          carry = (dd + d) / 10;
        } else {
          sol[i] = '0';
        }
      }
    }
    cout << sol << '\n';
  }
  return 0;
}
