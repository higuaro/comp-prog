#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t a, b, c; cin >> a >> b >> c;
    int64_t A, B, C; 
    A = a; B = 2 * b; C = 3 * c;
    int64_t AC = A + C;
    if (!(AC & 1)) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
