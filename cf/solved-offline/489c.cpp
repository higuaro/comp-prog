#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, s; cin >> m >> s;
  if (!s) {
    cout << (m == 1 ? "0 0" : "-1 -1") << '\n';
    return 0;
  }

  vector<int> n(m, 0);
  for (int i = m - 1; i >= 0; i--) {
    int d = min(9, s);
    s -= d;
    n[i] = d;
    if (!s) break;
  }

  if (s) {
    cout << "-1 -1" << endl;
    return 0;
  }

  if (!n[0]) {
    cout << '1';
    bool in_debt = true;
    for (int i = 1; i < m; i++)
      if (n[i] && in_debt) {
        cout << (n[i] - 1);
        in_debt = false;
      } else 
        cout << n[i];
  } else
    for (int digit : n) cout << digit;
  cout << ' ';

  sort(begin(n), end(n), greater<int>());
  for (int digit : n) cout << digit;
  cout << '\n';

  return 0;
}
