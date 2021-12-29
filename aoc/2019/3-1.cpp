#include <bits/stdc++.h>
using namespace std;
inline void mark_board_at(map<pair<int, int>, int>& board, int x, int y, int wire) {
  auto p = make_pair(x, y);
  auto b = board[p];
  board[p] = !b || b == wire ? wire : -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  map<pair<int, int>, int> board;
  string line;
  int wire = 1;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string token;
    int xo, yo, xf, yf;
    xo = yo = xf = yf = 0;
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
      for (int x = xo; x != xf; x += dx) mark_board_at(board, x, yo, wire);
      for (int y = yo; y != yf; y += dy) mark_board_at(board, xo, y, wire);
      xo = xf; yo = yf;
    }
    mark_board_at(board, xf, yf, wire);
    wire++;
  }

  int min_d = numeric_limits<int>::max();
  for (auto e : board) {
    if (e.second == -1) {
      auto p = e.first;
      int d = abs(p.first) + abs(p.second);
      if (d && d < min_d) min_d = d;
    }
  }
  cout << min_d << endl;
  return 0;
}
