#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c;
  for (int k = a; k <= b; k++)
    if (!(k % c)) {
      cout << k << endl;
      return 0;
    }
  cout << -1 << endl;
  return 0;
}
