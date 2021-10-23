#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  int n = s.size();
  cout << (n > 2 ? (s[n - 1] == 'r' && s[n - 2] == 'e' ? "er" : "ist") : "er") << endl;
  return 0;
}
