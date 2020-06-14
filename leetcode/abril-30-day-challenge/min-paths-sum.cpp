#include <bits/stdc++.h>
using namespace std;

class Solution {
  static const int oo = numeric_limits<int>::max();
public:
  int solve(const vector<vector<int>>& g, vector<vector<int>>& memo,
            const int n, const int m, const int i, const int j) {
    if (i == n - 1 && j == m - 1) return g[i][j];
    if (i < 0 || n <= i) return oo;
    if (j < 0 || m <= j) return oo;
    if (memo[i][j] != -1) return memo[i][j];
    int c = g[i][j];
    memo[i][j] = c + min(solve(g, memo, n, m, i + 1, j), 
                         solve(g, memo, n, m, i, j + 1));
    return memo[i][j];
  }
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> memo;
    for (int i = 0; i < n; i++)
      memo.push_back(vector<int>(m, -1));
    return solve(grid, memo, n, m, 0, 0); 
  }
};
