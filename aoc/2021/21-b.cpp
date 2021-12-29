#include <bits/stdc++.h>
using namespace std;

const int64_t oo = -1;

vector<int> pos(10, 0);
pair<int64_t, int64_t> dp[2][10][10][25][25];

pair<int64_t, int64_t> solve(
    bool turn, int pos1, int pos2, int score1, int score2
) {
  if (score1 >= 21) return {1, 0};
  if (score2 >= 21) return {0, 1};

  auto [dpu1, dpu2] = dp[turn][pos1][pos2][score1][score2];
  if (dpu1 != oo && dpu2 != oo) 
    return dp[turn][pos1][pos2][score1][score2];

  int64_t u1 = 0, u2 = 0;

  if (turn) {
    for (int d1 = 1; d1 <= 3; d1++)
      for (int d2 = 1; d2 <= 3; d2++)
        for (int d3 = 1; d3 <= 3; d3++) {
          int p = ((turn ? pos1 : pos2) + d1 + d2 + d3) % 10;
          int s = (turn ? score1 : score2) + pos[p];
          auto [uu1, uu2] = solve(!turn, p, pos2, s, score2);
          u1 += uu1;
          u2 += uu2;
        }
  } else {
    for (int d1 = 1; d1 <= 3; d1++)
      for (int d2 = 1; d2 <= 3; d2++)
        for (int d3 = 1; d3 <= 3; d3++) {
          int p = (pos2 + d1 + d2 + d3) % 10;
          int s = score2 + pos[p];
          auto [uu1, uu2] = solve(!turn, pos1, p, score1, s);
          u1 += uu1;
          u2 += uu2;
        }
  }

  return dp[turn][pos1][pos2][score1][score2] = {u1, u2};
}

int main() {
  int p1 = 9 - 1;
  int p2 = 10 - 1;

  for (int t = 0; t < 2; t++) 
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++) 
        for (int p = 0; p < 25; p++)
          for (int q = 0; q < 25; q++) 
            dp[t][i][j][p][q] = {oo, oo};

  iota(begin(pos), end(pos), 1);

  auto [u1, u2] = solve(true, p1, p2, 0, 0);
  cout << u1 << ',' << u2 << endl;
  cout << max(u1, u2) << endl;
  return 0;
}
