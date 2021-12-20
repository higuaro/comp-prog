#include <iostream>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
struct board_t {
  int last;
  vector<vector<int>> b;
  vector<vector<bool>> m;
  board_t() : b(5, vector<int>(5, 0)), m(5, vector<bool>(5, 0)) {}
  void play(const int ni) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (b[i][j] == ni) {
          m[i][j] = true;
          last = ni;
          return;
        }
      }
    }
  }
  int score() {
    int s = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (!m[i][j]) 
          s += b[i][j];
      }
    }
    return last * s;
  }
  bool wins() {
    for (int i = 0; i < 5; i++) {
      bool wins = true;
      for (int j = 0; j < 5; j++) {
        if (!m[i][j]) {
          wins = false;
          break;
        }
      }
      if (wins) return true;
      wins = true;
      for (int j = 0; j < 5; j++) {
        if (!m[j][i]) {
          wins = false;
          break;
        }
      }
      if (wins) return true;
    }
    return false;
    //bool d1 = true;
    //bool d2 = true;
    //for (int i = 0; i < 5; i++) {
    //  if (!b.m[i][i]) d1 = false;
    //  if (!b.m[i][5 - i - 1]) d2 = false;
    //}
    //return d1 || d2;
  }
  void print() {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cout << setfill(' ') << setw(3) <<  b[i][j] << ' ';
      }
      cout << endl;
    }
  }
};
int main() {
  string s; cin >> s;
  replace(begin(s), end(s), ',', ' ');
  istringstream iss(s);
  vector<int> n;
  int ni;
  while (iss >> ni) 
    n.push_back(ni);
  const int num_boards = 100;
  vector<board_t> boards;
  for (int i = 0; i < num_boards; i++) {
    board_t board;
    for (int ii = 0; ii < 5; ii++) 
      for (int jj = 0; jj < 5; jj++) 
        cin >> board.b[ii][jj];
    boards.push_back(board);
  }

  vector<board_t> winners;
  for (auto ni : n) {
    for (auto& board : boards) {
      board.play(ni);
      if (board.wins()) {
        cout << board.score() << endl;
        board.print();
        return 0;
      }
    }
  }

  return 0;
}
