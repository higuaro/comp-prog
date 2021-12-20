#include <bits/stdc++.h>
using namespace std;
int main() {
  string line;
  bool parsing_coords = true;
  vector<pair<int, int>> coords;
  vector<int> fold_y, fold_x;
  vector<bool> fold_type;
  int h = 0, w = 0;
  while (getline(cin, line)) {
    replace(begin(line), end(line), '=', ' ');
    replace(begin(line), end(line), ',', ' ');
    if (line == "") {
      parsing_coords = false;
      continue;
    }
    istringstream iss(line);
    if (parsing_coords) {
      int x, y; iss >> x >> y;
      coords.push_back({x, y});
      w = max(w, x + 1);
      h = max(h, y + 1);
    } else{
      string s1, s2, s3; int f;
      iss >> s1 >> s2 >> s3 >> f;
      if (s3 == "x") {
        fold_x.push_back(f);
        fold_type.push_back(false);
      } else {
        fold_y.push_back(f);
        fold_type.push_back(true);
      }
    }
  }

  vector<vector<char>> p(h, vector<char>(w, '.'));
  for (auto [x, y] : coords) p[y][x] = '#';

  int fxi = 0, fyi = 0;
  for (auto ft : fold_type) {
    int y_start = ft ? fold_y[fyi++] : 0;
    int x_start = !ft ? fold_x[fxi++] : 0;
    for (int y = y_start; y < h; y++) {
      for (int x = x_start; x < w; x++) {
        if (p[y][x] == '#') {
          if (ft) 
            p[h - 1 - y][x] = '#';
          else
            p[y][w - 1 - x] = '#';
        }
      }
    }
    if (ft) 
      h = y_start;
    else 
      w = x_start;
  }

  int marks = 0;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      cout << p[y][x];
      if (p[y][x] == '#') marks++;
    }
    cout << endl;
  }
  cout << marks << endl;
  return 0;
}
