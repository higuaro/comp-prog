#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
void draw(const vector<vector<char>>& screen) {
  size_t h = screen.size();
  for (size_t r = 0; r < h; r++) {
    auto& row = screen[r];
    auto w = row.size();
    for (size_t c = 0; c < w; c++)
      cout << screen[r][c];
    cout << endl;
  }
}

int main() {
  vector<vector<char>> screen;
  vector<char> current_row;

  ifstream program_file("17.in");
  auto program = intcode::parse_rom(program_file);
  intcode mac{program,
    []() -> int64_t { int t; cin >> t; return t; },
    [&](int64_t v) {
      char c = static_cast<char>(v);
      if (c == '\n') {
        if (current_row.size())
          screen.push_back(current_row);
        current_row.clear();
        return;
      }
      current_row.push_back(c);
    }
  };

  mac.run();
  draw(screen);

  vector<pair<int, int>> intersections;
  int offset_row[]{0, -1, 0, 1};
  int offset_col[]{-1, 0, 1, 0};
  size_t h = screen.size();
  for (size_t r = 0; r < h; r++) {
    auto& row = screen[r];
    size_t w = row.size();
    for (size_t c = 0; c < w; c++) {
      char ch = row[c];
      if (ch != '#' && ch != '<' && ch != '^' && ch != '>' && ch != 'v')
        continue;

      size_t blocks = 0;
      for (int k = 0; k < 4; k++) {
        int R = r + offset_row[k];
        int C = c + offset_col[k];
        if (R < 0 || R >= static_cast<int>(h)
            || C < 0 || C >= static_cast<int>(w))
          continue;
        if (screen[R][C] == '#') blocks++;
      }
      if (blocks == 4)
        intersections.push_back({r, c});
    }
  }

  int sum = 0;
  for (auto inter : intersections) {
    sum += inter.first * inter.second;
  }
  cout << sum << endl;
}
