#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> s(3, "");
  cin >> s[0] >> s[1] >> s[2];
  string t; cin >> t;
  string o = "";
  for (auto c : t) o += s[c - '1'];
  cout << o << endl;
  return 0;
}
