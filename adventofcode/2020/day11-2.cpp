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
int count_occupied(const vector<string>& g, int i, int j) {
  int n = g.size();
  int m = g[0].size();
  int occupied = 0;
  for (int p = -1; p <= 1; p++) {
    for (int q = -1; q <= 1; q++) {
      if (!p && !q) continue;
      int k = 1;
      bool found_occupied = false;
      do {
        int oi = i + p * k;
        int oj = j + q * k;
        if (!(0 <= oi && oi < n && 0 <= oj && oj < m)) break;
        char c = g[oi][oj];
        if (c == '#') {
          found_occupied = true;
          break;
        }
        if (c == 'L') break;
        k++;
      } while (true);
      if (found_occupied) occupied++;
    }
  }
  return occupied;
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
          case '#':
          case 'L':
            int occupied = count_occupied(g, i, j);
            if (c == 'L' && !occupied) {
              g2[i][j] = '#';
              break;
            }
            if (occupied >= 5)
              g2[i][j] = 'L';
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
