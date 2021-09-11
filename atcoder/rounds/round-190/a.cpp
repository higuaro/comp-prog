#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c;
  bool aoki = c;
  a++; b++;
  while (a && b) {
    if (aoki) b--;
    else a--;
    aoki = !aoki;
  }
  cout << (a ? "Takahashi" : "Aoki") << endl;
  return 0;
}
