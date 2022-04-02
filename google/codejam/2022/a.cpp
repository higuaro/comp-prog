#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, T; cin >> T; t = T;
  while (t--) {
    int r, c; cin >> r >> c;
    cout << "Case #" << (T - t) << ":\n";
    cout << "..+";
    for (int ci = 1; ci < c; ci++) cout << "-+"; cout << "\n..|";
    for (int ci = 1; ci < c; ci++) cout << ".|"; cout << "\n+";
    for (int ci = 0; ci < c; ci++) cout << "-+"; cout << '\n';
    for (int ri = 1; ri < r; ri++) {
      cout << '|';
      for (int ci = 0; ci < c; ci++) cout << ".|";
      cout << "\n+";
      for (int ci = 0; ci < c; ci++) cout << "-+";
      cout << '\n';
    }
  }
  return 0;
}
