#include <bits/stdc++.h>
using namespace std;
typedef bitset<2000> visited;
int solve(map<tuple<int, int, string>, int> memo, 
    int f, int r, int n, const string& rooms, visited& v) {
  auto t = make_tuple(f, r, v.to_string());
  if (memo.count(t)) return memo[t];

  vector<pair<int, int>> moves;
  int off_f[4] = {0, 1, 0, -1};
  int off_r[4] = {1, 0, -1, 0};
  v[n * f + r] = 1;
  for (int k = 0; k < 4; k++) {
    int df = rooms[r] == '1' ? f + off_f[k] : f;
    int dr = r + off_r[k];
    if (dr < 0 || dr >= n || df > 1 || df < 0 || v[df * n + dr]) continue;
    moves.push_back(make_pair(df, dr));
  }
  int best = 0;
  for (auto [mf, mr] : moves)
    best = max(best, solve(memo, mf, mr, n, rooms, v));
  v[n * f + r] = 0;

  memo[t] = 1 + best;
  return 1 + best;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string rooms; cin >> rooms;
    int best = 0;
    for (int f = 0; f < 1; f++) {
      for (int r = 0; r < n; r++) {
        visited v;
        map<tuple<int, int, string>, int> memo;
        int m = solve(memo, f, r, n, rooms, v);
        best = max(m, best);
      }
    }
    cout << best << endl;
  }

  return 0;
}
