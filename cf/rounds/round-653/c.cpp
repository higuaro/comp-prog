#include <bits/stdc++.h>
using namespace std;
bool is_reg(const string& s) {
  int p = 0;
  for (auto ch : s) {
    p += ch == '(' ? 1 : -1;
    if (p < 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    if (is_reg(s)) {
      cout << 0 << endl;
      continue;
    }
    int min_p = numeric_limits<int>::max();
    int max_p = numeric_limits<int>::min();
    int p = 0;
    for (auto ch : s) {
      p += ch == '(' ? 1 : -1;
      min_p = min(p, min_p);
      max_p = max(p, max_p);
    }
// cerr << min_p << ',' << max_p << endl;
    cout << abs(min_p) << endl;
  }
  return 0;
}
