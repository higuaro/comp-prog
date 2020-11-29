#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    int x[] = {1, w, 1, w};
    int y[] = {1, 1, h, h};
    int mm = -1;
    for (int i = 0; i < 4; i++) {
      int d = abs(x[i] - c) + abs(y[i] - r);
      mm = max(d, mm);
    }
    cout << mm << endl;
  }
  return 0;
}
