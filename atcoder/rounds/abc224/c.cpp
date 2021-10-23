#include <bits/stdc++.h>
using namespace std;
int area_2x(const pair<int, int>& pi, 
    const pair<int, int>& pj, 
    const pair<int, int>& pk) {
  auto [a, b] = pi;
  auto [d, e] = pj;
  auto [g, h] = pk;

  return (a * (e - h) - b * (d - g) + (d * h - e * g));
}
int main() {
  int n; cin >> n;
  vector<pair<int, int>> p(n, {0, 0});
  for (auto& pi : p) cin >> pi.first >> pi.second;

  //cout << "1, 2, 3 = " << area_2x(p[0], p[1], p[2]) << endl;
  
  int t = 0;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (area_2x(p[i], p[j], p[k]) < 0) {
          t++;
          //cout << (i + 1) << ' ' << (j + 1) << ' ' << (k + 1) << endl;
        }
      }
    }
  cout << (t / 3) << endl;
  return 0;
}
