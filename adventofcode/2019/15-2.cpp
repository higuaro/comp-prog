#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;

const int K = 4;

enum objs {EMPTY, PATH, BLOCK, OXYGEN};
array<char, 4> symbols{' ', '.', '#', 'O'};

array<array<objs, K>, K> board;

enum dirs {NORTH = 1, SOUTH, WEST, EAST};
array<int, 4> offset_row{-1, 1, 0, 0};
array<int, 4> offset_col{0, 0, -1, 1};

void draw_screen(size_t row, size_t col, vector<pair<int, int>> sol) {
  array<array<char, K>, K> screen;
  for (size_t r = 0; r < K; r++)
    for (size_t c = 0; c < K; c++)
      if (r == K / 2 && c == K / 2) {
        screen[r][c] = 'x';
      } else {
        auto b = board[r][c];
        screen[r][c] = r == row && c == col ? 'D' : symbols[b];
      }

  for (auto p : sol) {
    int r = p.first;
    int c = p.second;
    char ch = screen[r][c];
    if (ch == '.') screen[r][c] = '*';
  }

  for (size_t r = 0; r < K; r++) {
    for (size_t c = 0; c < K; c++)
      cout << screen[r][c];
    cout << endl;
  }
}

vector<pair<int, int>> find_min_path(int ro, int co, int rf, int cf) {
  struct node {
    int row, col;
    shared_ptr<node> parent;
    node(int row, int col, shared_ptr<node> parent) :
      row(row), col(col), parent(parent) {}
  };

  queue<shared_ptr<node>> states;
  set<pair<int, int>> reported;
  reported.insert({ro, co});
  states.push(make_shared<node>(ro, co, nullptr));

  while (!states.empty()) {
    auto state = move(states.front());
    states.pop();

    for (int d = 0; d < 4; d++) {
      int r = state->row + offset_row[d];
      int c = state->col + offset_col[d];

      if (r == rf && c == cf) {
        vector<pair<int, int>> trail;
        shared_ptr<node> s = make_shared<node>(r, c, state);
        while (s->parent != nullptr) {
          trail.push_back({s->row, s->col});
          s = s->parent;
        }
        trail.push_back({s->row, s->col});
        reverse(begin(trail), end(trail));
        return trail;
      }
      if (r < 0 || r >= K || c < 0 || c >= K) continue;
      auto b = board[r][c];
      if ((b == PATH || b == OXYGEN) && !reported.count({r, c})) {
        states.push(make_shared<node>(r, c, state));
        reported.insert({r, c});
      }
    }
  }
  return {};
}

dirs direction(int current_row, int current_col, int dest_row, int dest_col) {
  if (dest_row == current_row)
    return dest_col < current_col ? WEST : EAST;
  return dest_row < current_row ? NORTH : SOUTH;
}

int compute_oxygen_spread(int oxygen_row, int oxygen_col) {
  struct node {
    int r, c, d;
  };
  queue<node> states;
  set<pair<int, int>> visited;
  int seconds = 0;

  states.push({oxygen_row, oxygen_col, 0});
  while (!states.empty()) {
    auto state = states.front(); states.pop();

    for (int d = 0; d < 4; d++) {
      int r = state.r + offset_row[d];
      int c = state.c + offset_col[d];

      if (r < 0 || r >= K || c < 0 || c >= K) continue;
      if (visited.count({r, c}) || board[r][c] != PATH) continue;
      board[r][c] = OXYGEN;
      states.push({r, c, state.d + 1});
      seconds = max(state.d + 1, seconds);
    }
  }

  return seconds;
}

int main() {
  ifstream fis("15.in");

  size_t current_row, current_col;
  current_row = current_col = K / 2;
  board[current_row][current_col] = PATH;

  dirs dir = NORTH;

  vector<pair<int, int>> moves;
  size_t move_index = 0;

  set<pair<int, int>> reported;
  stack<pair<int, int>> to_explore;

  int oxygen_row = 0;
  int oxygen_col = 0;

  auto program = intcode::parse_rom(fis);
  intcode mac{program,
    [&]() -> int64_t {
      if (++move_index < moves.size()) {
        auto [dest_row, dest_col] = moves[move_index];
        dir = direction(current_row, current_col, dest_row, dest_col);
        return dir;
      }

      for (size_t d = 0; d < 4; d++) {
        int r = current_row + offset_row[d];
        int c = current_col + offset_col[d];
        auto o = board[r][c];
        if (0 <= r && r < K && 0 <= c && c < K
            && o == EMPTY && !reported.count({r, c})) {
          reported.insert({r, c});
          to_explore.push({r, c});
        }
      }

      if (to_explore.empty()) {
        auto sol = find_min_path(K / 2, K / 2, oxygen_row, oxygen_col);
        draw_screen(current_row, current_col, sol);
        cout << sol.size() << endl;
        cout << "done" << endl;
        cout << compute_oxygen_spread(oxygen_row, oxygen_col) << endl;
        exit(0);
      }

      auto dest = to_explore.top(); to_explore.pop();
      moves = find_min_path(current_row, current_col, dest.first, dest.second);
      move_index = 1; // discard first one, as is the current position
      auto [mr, mc] = moves[move_index];
      dir = direction(current_row, current_col, mr, mc);
      return dir;
    },

    [&](int64_t v) {
      int r = current_row + offset_row[dir - 1];
      int c = current_col + offset_col[dir - 1];
      switch (v) {
        case 0:
          board[r][c] = BLOCK;
          break;
        case 1:
          board[r][c] = PATH;
          current_row = r;
          current_col = c;
          break;
        case 2:
          current_row = r;
          current_col = c;
          oxygen_row = r;
          oxygen_col = c;
          board[r][c] = OXYGEN;
          break;
      }
      // draw_screen(current_row, current_col, {});
      // this_thread::sleep_for(chrono::milliseconds(10));
    }
  };
  mac.run();

  return 0;
}
