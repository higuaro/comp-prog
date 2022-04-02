#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int p; cin >> p;
  int m = p / 2 + 1;
  cout << m << endl;
  for (int r = 1, c = 1, n = 1; n <= p; n++) {
    cout << r << ' ' << c << endl;
    if (n & 1) c++;
    else r++;
  }
  return 0;
}
