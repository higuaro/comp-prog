#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  while (k--) {
    if (b <= a) {
      b *= 2;
      continue;
    }
    if (c <= b) {
      c *= 2;
      continue;
    }
    break;
  }
  cout << (a < b && b < c ? "Yes" : "No") << endl;
  return 0;
}
