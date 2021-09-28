#include <bits/stdc++.h>
using namespace std;
bool is_valid(int m) {
  int mat[4][4];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      mat[i][j] = (m >> (15 - i * 4 + j)) & 1;

  
  cout << "-------- " << bitset<16>(m) << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << mat[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "--------" << endl;

  int o[5] = {-1, 0, 1, 0, -1};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      if (mat[i][j]) {
        int neighbours = 0;
        for (int k = 0; k < 4; k++) {
          int ii = i + o[k];
          int jj = j + o[k + 1];
          if (0 <= ii && ii < 4 && 0 <= jj && jj < 4)
            if (mat[ii][jj]) neighbours++;
        }
        if (!neighbours) return false;
      }
    }
  return true;
}
int main() {
  int m = 0;
  for (int i = 0; i < 16; i++) {
    int mi; cin >> mi;
    m |= mi << (15 - i);
  }
  int bits = __builtin_popcount(m);
  int t = 0;
  for (int k = 0; k < 65535; k++) {
    if (!(m & k)) continue;
    if (bits == 1 || is_valid(k)) t++;
  }
  cout << t << endl;
}
