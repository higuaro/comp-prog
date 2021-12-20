#include <bits/stdc++.h>
using namespace std;
const int oo = numeric_limits<int>::max();
int dp[100][100];
int solve(const vector<string>& b, const int w, const int h, int i = 0, int j = 0) {
  if (i >= h || j >= w) return oo;
  if (i == h - 1 && j == w - 1) return b[i][j] - '0';
  if (dp[i][j] != -1) return dp[i][j];
  int c = b[i][j] - '0';
  return dp[i][j] = c + min(solve(b, w, h, i + 1, j), solve(b, w, h, i, j + 1));
}
int main() {
  vector<string> lines;
  string line;
  memset(dp, -1, sizeof dp);
  while (cin >> line)
    lines.push_back(line);
  int h = lines.size();
  int w = lines[0].size();
  cout << solve(lines, w, h) - (lines[0][0] - '0') << endl;
  return 0;
}
