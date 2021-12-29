#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
typedef vector<vector<char>> screen_t;
void draw(const screen_t& screen, const int W, const int H) {
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W ; x++)
      cout << screen[y][x];
    cout << endl;
  }
}
int main() {
  ifstream program("19.in");
  auto rom = intcode::parse_rom(program);

  const int H = 50, W = 50;
  screen_t map;
  int affected = 0;
  for (int y = 0; y < H; y++) {
    vector<char> row;
    for (int x = 0; x < W; x++)
      row.push_back('.');
    map.push_back(row);
  }

  int x = 0, y = 0, count = 0;
  intcode machine{
    rom,
    [&]() {
      int64_t v = count ? y : x;
      count = (count + 1) % 2;
      return v;
    },
    [&](int64_t v) {
      if (v) { 
        map[y][x] = '#';
        affected++;
      }
      if (++y == H) {
        x++;
        y = 0;
      }
    }
  };
  for (int steps = 0; steps < W * H; steps++) {
    machine.run();
    machine.reset();
  }
  draw(map, W, H);
  cout << "# affected = " << affected << endl;
  return 0;
}
