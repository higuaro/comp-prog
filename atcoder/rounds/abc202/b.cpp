#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  reverse(begin(s), end(s));
  for (int i = 0; i < s.size(); i++) {
    auto c = s[i];
    s[i] = c == '6' ? '9' : (c == '9' ? '6' : c);
  }
  cout << s << endl;
  return 0;
}
