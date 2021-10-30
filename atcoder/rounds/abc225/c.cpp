#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  vector<vector<int64_t>> b(n, vector<int64_t>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i > 0) {
        if (b[i][j] - b[i - 1][j] != 7) {
          cout << "No" << endl;
          return 0;
        }
      }
      if (j > 0) {
        if (b[i][j] - b[i][j - 1] != 1) {
          cout << "No" << endl;
          return 0;
        }
        if (!(b[i][j - 1] % 7) && (b[i][j] % 7) == 1) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
