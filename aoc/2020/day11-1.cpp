#include <bits/stdc++.h>
using namespace std;
void d(const vector<string>& g) {
  int n = g.size();
  int m = g[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
int main() {
  vector<string> g;
  string line;
  while (cin >> line) g.push_back(line);
  int n = g.size();
  int m = g[0].size();

  bool changed = true;
  while (changed) {
    d(g);
    vector<string> g2(g);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c = g[i][j];
        switch (c) {
          case '.': break;
          case 'L': {
            bool found_occupied = false;
            for (int q = -1; q <= 1; q++) {
              for (int p = -1; p <= 1; p++) {
                if (q == 0 && p == 0) continue;
                int oi = i + q;
                int oj = j + p;
                if (0 <= oi && oi < n && 
                    0 <= oj && oj < m && 
                    g[oi][oj] == '#') {
                  found_occupied = true;
                  break;
                }
              }
              if (found_occupied) break;
            }
            if (!found_occupied) 
              g2[i][j] = '#';
          }
          break;
          case '#': {
            int occupied = 0;
            for (int q = -1; q <= 1; q++) {
              for (int p = -1; p <= 1; p++) {
                if (q == 0 && p == 0) continue;
                int oi = i + q;
                int oj = j + p;
                if (0 <= oi && oi < n &&
                    0 <= oj && oj < m &&
                    g[oi][oj] == '#')
                  occupied++;
              }
            }
            if (occupied >= 4)
              g2[i][j] = 'L';
          }
          break;
        }
      }
    }
    changed = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (g2[i][j] != g[i][j]) {
          changed = true;
          break;
        }
      if (changed) break;
    }
    g = g2;
  }
  int seats = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '#') seats++;
  cout << seats << endl;

  return 0;
}
