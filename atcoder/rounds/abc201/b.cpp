#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<int, string>> m;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int t; cin >> t;
    m.push_back({t, s});
  }
  sort(begin(m), end(m), greater<pair<int, string>>());
  cout << m[1].second << endl;
  return 0;
}
