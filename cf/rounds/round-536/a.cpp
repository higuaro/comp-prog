#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  char m[501][501];
  int n; cin >> n;
  string line;
  ld t = 0;
  int k = 0;
  while (getline(cin, line, '\n')) {
    for (int i = 0; i < n; i++)
      m[k][i] = line[i];
    if (k > 1) {
      for (int i = 0; i < n - 2; i++) {
        char c1 = m[k - 2][i + 2]; //
        char c2 = m[k - 2][i    ]; // 
        char c3 = m[k - 1][i + 1]; //  X
        char c4 = m[k    ][i + 2]; //    X
        char c5 = m[k    ][i    ]; // X
        if (c1 == c2 && c2 == c3 && c3 == c4 && c4 == c5 && c5 == 'X') t++;
      }
    }
    k++;
  }
  cout << t << std::endl;
  return 0;
}
