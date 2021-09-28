#include <bits/stdc++.h>
using namespace std;
int main() {
  string x; cin >> x;
  int n; cin >> n;
  vector<string> s(n, "");
  for (auto& si : s) cin >> si;
  sort(begin(s), end(s), [&x](const string& s1, const string& s2) {
    string ss1;
    for (auto c : s1) ss1 += x[c - 'a'];
    string ss2;
    for (auto c : s2) ss2 += x[c - 'a'];
    clog << s1 << ':' << ss1 << ", " << s2 << ':' << ss2 << endl;
    return ss1 < ss2;
  });
  for (auto si : s) cout << si << '\n';
  return 0;
}
