#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
bool solve(const vector<int>& rots, int pos, int angle) {
  int alpha = angle + rots[pos];
  int beta = angle - rots[pos];
  if (pos == rots.size() - 1)
    return !(alpha % 360) || !(beta % 360);
  return solve(rots, pos + 1, alpha) || solve(rots, pos + 1, beta);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  vector<int> rots;
  int a;
  while (cin >> a) {
    rots.push_back(a);
  }
  cout << (solve(rots, 0, 0) ? "YES" : "NO") << std::endl;
  return 0;
}
