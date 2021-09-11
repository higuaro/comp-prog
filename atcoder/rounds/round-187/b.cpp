#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<int, int>> ps;
  const int N = n;
  while (n--) {
    int x, y; cin >> x >> y;
    ps.push_back({x, y});
  }
  int total = 0;
  for (int i = 0; i < N; i++) {
    auto [x1, y1] = ps[i];
    for (int j = i + 1; j < N; j++) {
      //if (i == j) continue;
      auto [x2, y2] = ps[j];
      int dx = x2 - x1;
      int dy = y2 - y1;
      if (abs(dx) >= abs(dy))
        total++;
    }
  }
  cout << total << endl;
  return 0;
}
