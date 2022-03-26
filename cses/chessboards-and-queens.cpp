#include <bits/stdc++.h>
using namespace std;
int total = 0;
inline bool v(int i) { return 0 <= i && i < 8; }
void place_queen(vector<string>& b, int r, int c, char state) {
  for (int ri = r; v(ri); ri--) b[ri][c] += state;
  for (int ri = r; v(ri); ri++) b[ri][c] += state;
  for (int ci = c; v(ci); ci--) b[r][ci] += state;
  for (int ci = c; v(ci); ci++) b[r][ci] += state;
  const int o[] = {-1,-1, 1,1, 1,-1, -1,1};
  for (int k = 0; k < 8; k += 2)
    for (int ci = c, ri = r; v(ci) && v(ri); ci += o[k], ri += o[k + 1])
      b[ri][ci] += state;
  b[r][c] = state == 1 ? 'q' : '.';
}
void solve(vector<string>& b, int r0 = 0, int q = 0) {
  if (q == 8) {
    total++; return;
  }

  for (int r = r0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if (b[r][c] == '.') {
        place_queen(b, r, c, 1);
        solve(b, r + 1, q + 1);
        place_queen(b, r, c, -1);
      }
    }
  }
}
int main() {
  vector<string> b(8, "");
  for (auto& row : b) {
    cin >> row;
    replace(begin(row), end(row), '*', '9');
  }
  solve(b);
  cout << total << endl;
  return 0;
}
