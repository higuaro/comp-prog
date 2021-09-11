#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<string> s(n, "");
  unordered_set<string> ss;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    ss.insert(s[i]);
  }
  for (auto& si : s) {
    string t = si[0] == '!' 
      ? si.substr(1, si.size() - 1) 
      : '!' + si;
    if (ss.count(t)) {
      cout << (t[0] == '!' ? t.substr(1, t.size() - 1) : t) << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
  return 0;
}
