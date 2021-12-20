#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;
typedef vector<vector<char>> board_t;
struct line_t {
  int x1, y1, x2, y2;
  bool is_vertical() {
    return x1 == x2;
  }
  bool is_diagonal_45() {
    return abs(x1 - x2) == abs(y1 - y2);
  }
  bool is_diagonal() {
    return x1 != x2 && y1 != y2 && !is_diagonal_45();
  }
};
int main() {
  string line;
  vector<line_t> lines;
  int max_x, max_y;
  max_x = max_y = 0;
  while (getline(cin, line)) {
    replace(begin(line), end(line), ',', ' ');
    replace(begin(line), end(line), '-', ' ');
    replace(begin(line), end(line), '>', ' ');
    istringstream iss(line);
    line_t l;
    iss >> l.x1 >> l.y1 >> l.x2 >> l.y2;
    max_x = max(max_x, max(l.x1, l.x2));
    max_y = max(max_y, max(l.y1, l.y2));
    lines.push_back(l);
  }
  max_y++;
  max_x++;
  vector<vector<char>> board(max_y, vector<char>(max_x, 0));
  for (auto& l : lines) {
    if (l.is_diagonal()) continue;
    if (l.is_diagonal_45()) {
      int dy = l.y1 > l.y2 ? -1 : 1;
      int dx = l.x1 > l.x2 ? -1 : 1;
      int y = l.y1, x = l.x1;
      while (y != l.y2 && x != l.x2) {
        board[y][x]++;
        y += dy; x += dx;
      }
      board[y][x]++;
    } else if (l.is_vertical()) {
      for (int y = min(l.y1, l.y2); y <= max(l.y1, l.y2); y++) 
        board[y][l.x1]++;
    } else {
      for (int x = min(l.x1, l.x2); x <= max(l.x1, l.x2); x++)
        board[l.y1][x]++;
    }
  }
  int c = 0;
  for (int y = 0; y < max_y; y++) {
    for (int x = 0; x < max_x; x++) {
      if (board[y][x] > 1) c++;
    }
  }
  cout << c << endl;

  return 0;
}
