#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w, k; cin >> h >> w >> k;
  vector<string> c(h, "");
  for (int i = 0; i < h; i++)
    cin >> c[i];

  int t = 0;
  for (int b = 0; b < (1 << (w + h)); b++) {
    int kk = 0;
    for (int y = 0; y < h; y++) {
      int m = b >> (w + y);
      if (!(m & 1)) continue;
      for (int x = 0; x < w; x++) {
        int m = b >> x;
        if ((m & 1) && c[y][x] == '#') kk++;
      }
    }
    if (kk == k) t++;
  }
  cout << t << endl;
  return 0;
}
