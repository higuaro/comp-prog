#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w; cin >> h >> w;
  vector<vector<char>> g(h, vector<char>(w, 0));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> g[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] != '.') continue;
      bool avail[5];
      memset(avail, true, 5);
      const int o[] = {-1, 0, 1, 0, -1};
      for (int k = 0; k < 4; k++) {
        int ii = i + o[k];
        int jj = j + o[k + 1];
        if (ii < 0 || ii >= h || jj < 0 || jj >= w) continue;
        char c = g[ii][jj];
        if (c == '.') continue;
        avail[c - '1'] = false;
      }
      int color = 0;
      for (int k = 0; k < 5; k++) 
        if (avail[k]) {
          color = k + 1;
          break;
        }
      g[i][j] = static_cast<char>(color + '0');
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
  return 0;
}
