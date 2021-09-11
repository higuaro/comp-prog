#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x; cin >> n >> x;
  int t = 0;
  for (int i = 1; i <= n; i++) {
    int ai; cin >> ai;
    if (!(i % 2)) ai--;
    t += ai;
  }
  cout << (x >= t ? "Yes" : "No") << endl;
  return 0;
}
