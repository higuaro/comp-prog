#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int t = 0;
  for (int i = a; i <= b; i++) {
    for (int j = b; j <= c; j++) {
      int l = a + b;
      if (l > c) { 
        t += (c - j + 1);
        break;
      }
    }
  }

  cout << t << endl;

  return 0;
}
