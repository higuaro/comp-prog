#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
void draw_screen(vector<vector<int>> screen, const int W, const int H, int score) {
  char objs[] = {' ', '|', '#', '_', 'o'};
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int v = screen[y][x];
      cout << objs[v];
    }
    cout << endl;
  }
  cout << "score: " << score << "\n\n\n" << endl;
}

int find_obj_x(vector<vector<int>> screen, const int W, const int H, int obj) {
  for (int y = 0; y < H; y++)
    for (int x = 0; x < W; x++)
      if (screen[y][x] == obj) return x;
  return -1;
}

int main() {
  ifstream program("13.in");
  auto rom = intcode::parse_rom(program);
  rom[0] = 2;

  bool ai = true;
  int count = 0;
  int score = 0;
  int64_t x, y;
  map<pair<int, int>, int> grid;

  const int W = 44; const int H = 24;
  vector<vector<int>> screen;
  for (int y = 0; y < H; y++) {
    vector<int> row(W, 0);
    screen.push_back(row);
  }

  draw_screen(screen, W, H, score);
  intcode mac{
    rom,
    [&]() {
      draw_screen(screen, W, H, score);
      if (ai) {
        int paddle_x = find_obj_x(screen, W, H, 3);
        int ball_x = find_obj_x(screen, W, H, 4);

        std::this_thread::sleep_for(std::chrono::milliseconds(40));

        return paddle_x == ball_x ? 0L : (paddle_x > ball_x ? -1L : 1L);
      } else {
        cout << "play> ";
        cout.flush();
        int64_t v; cin >> v;
        return v;
      }
    },
    [&](int64_t v) {
      switch (count) {
        case 0: x = v; break;
        case 1: y = v; break;
        case 2:
          if (x == -1)
            score = v;
          else
            screen[y][x] = v;
         break;
      }
      count = (count + 1) % 3;
    }
  };

  mac.run();
  draw_screen(screen, W, H, score);

  return 0;
}
