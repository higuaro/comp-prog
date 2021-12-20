#include <bits/stdc++.h>
using namespace std;
int main() {
  string line;
  vector<pair<int, int>> coords;
  int max_r = 0, max_c = 0;
  vector<int> fxs, fys;
  vector<bool> fold_types;
  bool parsing_coords = true;
  while (getline(cin, line)) {
    if (line == "") {
      parsing_coords = false;
      continue;
    }
    if (parsing_coords) {
      replace(begin(line), end(line), ',', ' ');
      istringstream iss(line);
      int c, r; iss >> c >> r;
      coords.push_back({c, r});
      max_r = max(r, max_r);
      max_c = max(c, max_c);
    } else {
      string s1, s2, s3; int f;

      replace(begin(line), end(line), '=', ' ');
      istringstream iss(line);
      iss >> s1 >> s2 >> s3 >> f;
      if (s3 == "x") {
        fxs.push_back(f);
        fold_types.push_back(false);
      } else {
        fys.push_back(f);
        fold_types.push_back(true);
      }
    }
  }

  int h = max_r + 1;
  int w = max_c + 1;
  vector<vector<char>> p(h, vector<char>(w, '.'));
  for (auto [c, r] : coords) {
    p[r][c] = '#';
  }

  int h2 = h, w2 = w;
  int fyi = 0, fxi = 0;
  for (auto fold_type : fold_types) {
    int rs = fold_type ? fys[fyi] : 0;
    int cs = !fold_type ? fxs[fxi] : 0;
    for (int r = rs; r < h2; r++) {
      for (int c = cs; c < w2; c++) {
        if (p[r][c] == '#') {
          if (fold_type)
            p[h2 - r - 1][c] = '#';
          else
            p[r][w2 - c - 1] = '#';
        }
      }
    }
    if (fold_type) {
      h2 = rs; fyi++;
    } else {
      w2 = cs; fxi++;
    }
    break;
  }

  for (int r = 0; r < h2; r++) {
    for (int c = 0; c < w2; c++) {
      cout << p[r][c];
    }
    cout << endl;
  }

  int marks = 0;
  for (int r = 0; r < h2; r++) {
    for (int c = 0; c < w2; c++) {
      if (p[r][c] == '#') marks++;
    }
  }
  cout << marks << endl;
  return 0;
}
