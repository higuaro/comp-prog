#include <bits/stdc++.h>
using namespace std;
const int oo = 999999999;
int memo[301][301][301];
vector<pair<int, int>> ab;
int n;
int solve(int x, int y, int i = 0) {
  if (!x && !y) return 1;
  if (i > ab.size()) return oo;
  int ignore = solve(x, y, i + 1);
  auto [xi, yi] = ab[i];
  int take = 1 + solve(max(x - xi, 0), max(y - yi, 0), i + 1);
  return min(ignore, take);
}
int main() {
  cin >> n;
  int x, y; cin >> x >> y;
  for (int i = 0; i < n; i++) {
    int xi, yi; cin >> xi >> yi;
    ab.push_back({xi, yi});
  }
  int sol = solve(x, y);
  cout << (sol == oo ? -1 : sol) << endl;
  return 0;
}
