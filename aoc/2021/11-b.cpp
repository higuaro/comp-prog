#include <bits/stdc++.h>
using namespace std;
void step(vector<vector<bool>>& f, vector<vector<int>>& o, int i, int j) {
  const int h = o.size();
  const int w = o[0].size();
  o[i][j]++;
  if (f[i][j] || o[i][j] < 10) return;
  f[i][j] = true;
  for (int p = -1; p <= 1; p++) {
    for (int q = -1; q <= 1; q++) {
      if (!q && !p) continue;
      int ii = i + p;
      int jj = j + q;
      if (0 <= ii && ii < h && 0 <= jj && jj < w) {
        step(f, o, ii, jj);
      }
    }
  }
}
int main() {
  vector<vector<int>> o;
  string line; 
  int ii = 0;
  while (getline(cin, line)) {
    o.push_back({});
    for (auto c : line) 
      o[ii].push_back(c - '0');
    ii++;
  }
  int h = o.size();
  int w = o[0].size();
  for (int n = 0; ; n++) {
    vector<vector<bool>> f(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        step(f, o, i, j);
      }
    }
    int flashes = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) { 
        if (f[i][j]) flashes++;
        if (o[i][j] >= 10) o[i][j] = 0;
      }
    }
    if (flashes == w * h) {
      cout << n + 1 << endl;
      return 0;
    }
//cout << endl;
//for (int i = 0; i < h; i++) {
//  for (int j = 0; j < w; j++) {
//    cout << o[i][j];
//  }
//  cout << endl;
//}
//cout << flashes << endl;
  }
  return 0;
}
