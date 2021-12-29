#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> g; string line;
  while (getline(cin, line))
    g.push_back(line);

  int h = g.size();
  int w = g[0].size();

  vector<string> next_g = g;
  int steps = 0;
  do {
    g = next_g;
    vector<string> tmp(next_g);
    // move >
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (g[i][j] == '>') {
          int ii = i;
          int jj = (j + 1) % w;
          if (g[ii][jj] == '.') {
            tmp[ii][jj] = '>';
            tmp[i][j] = '.';
          }
        }
    next_g = tmp;
    // move v
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        if (tmp[i][j] == 'v') {
          int ii = (i + 1) % h;
          int jj = j;
          if (tmp[ii][jj] == '.') {
            next_g[ii][jj] = 'v';
            next_g[i][j] = '.';
          }
        }
    steps++;
  } while (next_g != g);
  cout << steps << endl;

  return 0;
}
