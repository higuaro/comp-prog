#include <bits/stdc++.h>
using namespace std;
unordered_set<string> seen;
unordered_set<string> sols;
void d(const int W, const int H, const vector<string>& m) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << m[i][j];
    }
    cout << endl;
  }
  cout << "---------" << endl;
}
pair<int, string> eval(const int W, const int H, const vector<string>& m) {
  int count = 0;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      if (m[i][j] == '#') count++;

  ostringstream oss;
  for (int i = 0; i < H; i++) oss << m[i];

  return {count, oss.str()};
}
void solve(const int W, const int H, const int K, const vector<string>& g,
    int ii, int jj) {
  if (ii >= H || jj >= W) return;
  auto [count, gs] = eval(W, H, g);
  if (seen.count(gs)) return;
  if (count < K) return;

  const char R = 'x';

  // paint row
  auto mr = g;
  for (int j = 0; j < W; j++) mr[ii][j] = R;
  auto [count_mr, sr] = eval(W, H, mr);
  if (count_mr == K && !sols.count(sr)) {
    d(W, H, mr);
    sols.insert(sr);
  }
  solve(W, H, K, mr, ii + 1, jj);
  solve(W, H, K, g, ii + 1, jj);

  // paint col
  auto mc = g;
  for (int i = 0; i < H; i++) mc[i][jj] = R;
  auto [count_mc, sc] = eval(W, H, mc);
  if (count_mc == K && !sols.count(sc)) {
    d(W, H, mc);
    sols.insert(sc);
  }
  solve(W, H, K, mc, ii, jj + 1);
  solve(W, H, K, g, ii, jj + 1);

  // col & row
  auto mrc = g;
  for (int j = 0; j < W; j++) mrc[ii][j] = R;
  auto [count_mrc, smrc] = eval(W, H, mrc);
  if (count_mrc == K && !sols.count(smrc)) {
    d(W, H, mrc);
    sols.insert(smrc);
  }
  solve(W, H, K, mrc, ii + 1, jj + 1);
  solve(W, H, K, g, ii + 1, jj + 1);

  seen.insert(gs);
}
int main() {
  int h, w, k; cin >> h >> w >> k;
  vector<string> g(h, "");
  for (int i = 0; i < h; i++)
    cin >> g[i];

  auto [c, _] = eval(w, h, g);
  if (c < k)
    cout << 0 << endl;
  else if (c == k)
    cout << 1 << endl;
  else {
    solve(w, h, k, g, 0, 0);
    cout << sols.size() << endl;
  }

  return 0;
}
