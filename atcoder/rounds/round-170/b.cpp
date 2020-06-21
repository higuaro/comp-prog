#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int solve(int x, int y) {
  if (x < 0 || y < 0) return 0;
  if (!x && !y) return 1;
  if (dp[x][y] != -1) return dp[x][y];
  int s = max(solve(x - 1, y - 4), solve(x - 1, y - 2));
  dp[x][y] = s;
  return s;
}
int main() {
  for (int i = 0; i < 101; i++) 
    for (int j = 0; j < 101; j++) 
      dp[i][j] = -1;
  int x, y; cin >> x >> y;
  int s = solve(x, y);
  cout << (s ? "Yes" : "No") << endl;
  return 0;
}
