#include <bits/stdc++.h>
using namespace std;
string d(const vector<vector<int>>& m) {
  const int oo = numeric_limits<int>::max();
  int rows = m.size();
  int cols = m[0].size();
  ostringstream o;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++)
      if (m[r][c] == oo)
        o << "oo" << ' ';
      else
        o << setw(2) << m[r][c] << ' ';
    o << '\n';
  }
  return o.str();
}

string d2(const vector<vector<int>>& m, 
    const vector<int>& minRows, 
    const vector<int>& minCols) {
  const int oo = numeric_limits<int>::max();
  int rows = m.size();
  int cols = m[0].size();
  ostringstream o;
  o << "    ";
  for (int c = 0; c < cols; c++)
    if (minCols[c] == -oo)
      o << " oo ";
    else
      o << setw(3) << minCols[c] << ' ';
  o << '\n' << '\n';
  for (int r = 0; r < rows; r++) {
    if (minRows[r] == -oo)
      o << " oo ";
    else
      o << setw(3) << minRows[r] << ' ';

    for (int c = 0; c < cols; c++)
      if (m[r][c] == oo)
        o << " oo ";
      else
        o << setw(3) << m[r][c] << ' ';
    o << '\n';
  }
  return o.str();
}
class Solution {
public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& m) {
    using t3 = tuple<int, int, int>;
    const int oo = numeric_limits<int>::max();
    int rows = m.size();
    int cols = m[0].size();
    vector<int> rowsMin(rows, -oo), colsMin(cols, -oo);
    vector<int> rowsRank(rows, 0), colsRank(cols, 0);
    priority_queue<t3, vector<t3>, greater<t3>> q;
    for (int r = 0; r < rows; r++)
      for (int c = 0; c < cols; c++)
        q.emplace(m[r][c], r, c);
    vector<vector<int>> sol(rows, vector<int>(cols, 0));
    while (!q.empty()) {
      auto [v, r, c] = q.top(); q.pop();
      int rank = max(rowsRank[r], colsRank[c]);
      int maxV = max(rowsMin[r], colsMin[c]);
cout << d2(sol, rowsMin, colsMin) << endl << r << ',' << c << "=" << v << '\n' << endl;
      if (v > maxV) rank++;
      rowsMin[r] = colsMin[c] = v; 
      rowsRank[r] = colsRank[c] = rank;
      sol[r][c] = rank;
    }
    return sol;
  }
};

int main() {
  vector<vector<int>> m = {{-37, -50,  -3,  44},
                           {-37,  46,  13, -32},
                           { 47, -42,  -3, -40},
                           {-17, -22, -39,  24}};
  Solution s;
  cout << d(s.matrixRankTransform(m)) << endl;
  return 0;
}
