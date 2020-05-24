#include <bits/stdc++.h>
using namespace std;
int main() {
  int k; cin >> k;
  int s = 0;
  for (int a = 1; a <= k; a++) {
    for (int b = 1; b <= k; b++) {
      for (int c = 1; c <= k; c++) {
        s += __gcd(a, __gcd(b, c));
      }
    }
  }
  cout << s << endl;
}
