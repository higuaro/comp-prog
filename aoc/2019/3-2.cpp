#include <bits/stdc++.h>
using namespace std;
inline void mark_board_at(map<pair<int, int>, pair<int, int>>& board,
    int x, int y, int steps, int wire) {
  auto p = make_pair(x, y);

  if (!board.count(p))
    board[p] = wire == 1 ? make_pair(steps, 0) : make_pair(0, steps);
  else {
    auto prev = board[p];
    if (wire == 1) {
      if (!prev.first)
        board[p] = make_pair(steps, prev.second);
    } else {
      if (!prev.second)
        board[p] = make_pair(prev.first, steps);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  map<pair<int, int>, pair<int, int>> board;
  string line;
  int wire = 1;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string token;
    int xo, yo, xf, yf;
    xo = yo = xf = yf = 0;
    int steps = 0;
    while (getline(iss, token, ',')) {
      int d = stoi(token.substr(1));
      xf = xo; yf = yo;
      switch (token[0]) {
        case 'R': xf += d; break;
        case 'L': xf -= d; break;
        case 'U': yf += d; break;
        case 'D': yf -= d; break;
      }

      int dx = xf > xo ? 1 : -1;
      int dy = yf > yo ? 1 : -1;

      for (int x = xo; x != xf; x += dx, steps++)
        mark_board_at(board, x, yo, steps, wire);

      for (int y = yo; y != yf; y += dy, steps++)
        mark_board_at(board, xo, y, steps, wire);

      xo = xf; yo = yf;
    }
    mark_board_at(board, xf, yf, steps, wire);
    wire++;
  }

  int min_d = numeric_limits<int>::max();
  for (auto e : board) {
    auto v = e.second;
    if (v.first && v.second) {
      int d = v.first + v.second;
      if (d && d < min_d) min_d = d;
    }
  }
  cout << min_d << endl;
  return 0;
}
