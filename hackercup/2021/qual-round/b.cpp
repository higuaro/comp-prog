#include <bits/stdc++.h>
using namespace std;
string win_board_str(const vector<string>& c, int n, bool is_row, int index) {
  ostringstream oss;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) 
      if ((is_row && i == index)  || (!is_row && j == index))
        oss << 'X';
      else
        oss << c[i][j];
    oss << '\n';
  }
  return oss.str();
}

int main() {
  const int oo = 1e8 - 1;
  int t; cin >> t;
  int T = 1;
  while (t--) {
    int n; cin >> n;
    vector<string> c(n, "");
    for (int i = 0; i < n; i++) cin >> c[i];

    unordered_map<int, vector<int>> w_rows;
    unordered_map<int, vector<int>> w_cols;

    int m = oo;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < 2; k++) {
        int spaces = 0;
        for (int j = 0; j < n; j++) {
          char cij = k & 1 ? c[j][i] : c[i][j];
          if (cij == 'O') {
            spaces = oo;
            break;
          } else if (cij == '.')
            spaces++;
        }
        if (spaces != oo) 
          (k & 1 ? w_cols : w_rows)[spaces].push_back(i);
        m = min(m, spaces);
      }
    }

    if (m == oo) {
      cout << "Case #" << T++ << ": Impossible" << endl;
      continue;
    }

    unordered_set<string> boards;
    for (int k = 0; k < 2; k++) {
      for (int row : (k & 1 ? w_cols : w_rows)[m]) {
        auto board = win_board_str(c, n, k == 0, row);
        if (!boards.count(board)) 
          boards.insert(board);
      }
    }
    //for (auto b : boards) cout << b << "\n\n";
    cout << "Case #" << T++ << ": " << m << ' ' << boards.size() << endl;
  }
  return 0;
}
