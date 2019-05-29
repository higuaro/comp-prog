#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string tc; cin >> tc;
  char v, r; v = tc[0]; r = tc[1];
  string card;
  while (cin >> card) {
    char vv, rr; vv = card[0]; rr = card[1];
    if (vv == v || rr == r) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << std::endl;
  return 0;
}
