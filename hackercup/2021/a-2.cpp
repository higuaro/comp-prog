#include <bits/stdc++.h>
using namespace std;
int main() {
  const int oo = 1e8 - 1;
  int t; cin >> t;
  int T = 1;
  while (t--) {
    string s; cin >> s;
    int k; cin >> k;

    vector<vector<int>> g(26, vector(26, oo));
    for (int i = 0; i < k; i++) {
      string ab; cin >> ab;
      int a = ab[0] - 'A';
      int b = ab[1] - 'A';
      g[a][b] = 1;
    }
    for (int i = 0; i < 26; i++) g[i][i] = 0;

    vector<vector<int>> d(26, vector(26, oo));
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) 
        d[i][j] = g[i][j];

    for (int k = 0; k < 26; k++) 
      for (int i = 0; i < 26; i++) 
        for (int j = 0; j < 26; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int m = oo;
    for (int b = 0; b < 26; b++) {
      int changes = 0;
      for (char c : s) {
        int a = c - 'A';
        if (a == b) continue;
        if (d[a][b] == oo) {
          changes = oo;
          break;
        }
        changes += d[a][b];
      }
      m = min(m, changes);
    }
    cout << "Case #" << T++ << ": " << (m == oo ? -1 : m) << endl;
  }
  return 0;
}
