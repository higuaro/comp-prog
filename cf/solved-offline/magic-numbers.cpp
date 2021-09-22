#include <bits/stdc++.h>
using namespace std;
string a, b;
int d, m;
int memo[2002][2000][2][2];
const int M = 1e9 + 7;

int solve(int i = 0, int r = 0, int gta = false, int ltb = false) {
  if (i > a.size()) return 0;
  if (i == a.size()) return r ? 0 : 1;
  if (memo[i][r][gta][ltb] != -1) return memo[i][r][gta][ltb];
  int min_dd = gta ? 0 : a[i] - '0';
  int max_dd = ltb ? 9 : b[i] - '0';
  int c = 0;
  for (int dd = min_dd; dd <= max_dd; dd++) {
    if ((i & 1) && dd != d) continue;
    if (!(i & 1) && dd == d) continue;
    bool gtai = gta || dd > (a[i] - '0');
    bool ltbi = ltb || dd < (b[i] - '0');
    int res = solve(i + 1, (r * 10 + dd) % m, gtai, ltbi) % M;
    c = (c + res) % M;
  }
  return memo[i][r][gta][ltb] = c;
}

int main() {
  cin >> m >> d >> a >> b;
  memset(memo, -1, sizeof memo);
  cout << solve() << endl;
  return 0;
}
