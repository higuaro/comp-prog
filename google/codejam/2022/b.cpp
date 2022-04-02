#include <bits/stdc++.h>
using namespace std;
int main() {
  const int M = 1e6;
  int t, T; cin >> T; t = T;
  while (t--) {
    int c, m, y, k;
    c = m = y = k = M + 1;
    for (int i = 0; i < 3; i++) {
      int ci, mi, yi, ki; 
      cin >> ci >> mi >> yi >> ki;
      c = min(c, ci); m = min(m, mi); y = min(y, yi); k = min(k, ki);
    }
    cout << "Case #" << (T - t) << ": ";
    if (c + m + y + k < M) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    vector<int> inks{c, m, y, k}, output(4, 0);
    int i = 0, ink = 0;
    while (ink < M) {
      if (ink + inks[i] > M) {
        output[i] = M - ink;
        break;
      }
      output[i] = inks[i];
      ink += inks[i];
      i++;
    }
    for (int j = 0; j < 4; j++)
      cout << output[j] << ' ';
    cout << '\n';
  }
  return 0;
}
