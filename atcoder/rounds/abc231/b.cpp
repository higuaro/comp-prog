#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  map<string, int> c;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    c[s]++;
  }

  string ss;
  int m = 0;
  for (auto [k, v] : c) {
    if (v > m) {
      ss = k;
      m = v;
    }
  }
  cout << ss << endl;

  return 0;
}
