#include <bits/stdc++.h>
using namespace std;
unordered_set<string> paths;
inline bool valid(const int k) { return 0 <= k && k <= 6; }
string to_path(const vector<vector<char>>& b) {
  string p;
  int r = 0, c = 0;
  while (r != 6 || c != 0) {
    char d = b[r][c];
    p += d;
    switch (d) {
      case 'D': r++; break;
      case 'U': r--; break;
      case 'L': c--; break;
      case 'R': c++; break;
      default: return p;
    }
  }
  return p;
}
void solve(vector<vector<char>>& b, const string& s, string& ss,
    int r = 0, int c = 0, int cells = 48) {
  if (r == 6 && c == 0 && cells) 
    return;
  if (r == 6 && c == 0 && !cells) {
    paths.insert(to_path(b));
    return;
  }
  //if ((c + 1) * (6 - r + 1) > cells - 1) 
  //  return;

  const int O[]{-1, 0, 1, 0, -1};
  const char D[]{'U', 'R', 'D', 'L'};
  for (int k = 0; k < 4; k++) {
    int rr = r + O[k];
    int cc = c + O[k + 1];
    if (valid(rr) && valid(cc) && !b[rr][cc]) {
      int i = 48 - cells;
      if (D[k] != s[i] && s[i] != '?') 
        continue;
      ss[i] = b[r][c] = D[k];
      solve(b, s, ss, rr, cc, cells - 1);
      ss[i] = b[r][c] = 0;
    }
  }
}
int main() {
  string s; cin >> s;
  string ss(48, 0);
  vector<vector<char>> b(7, vector<char>(7, 0));
  solve(b, s, ss);
  cout << paths.size() << endl;
  for (auto p : paths) 
    cout << p << endl;
  return 0;
}
