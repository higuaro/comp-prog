#include <bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N;
  double D, H; cin >> D >> H;
  vector<pair<double, double>> ds;
  vector<double> ms;
  for (int i = 0; i < N; i++) {
    double d, h; cin >> d >> h;
    ds.push_back({d, h});
    ms.push_back((H - h) / (D - d));
  }
  ds.push_back({0, 0});
  ms.push_back(H / D);
  N++;

  double b = 1000.0;
  for (int i = 0; i < N; i++) {
    auto [di, hi] = ds[i];
    auto mi = ms[i];
    double bi = hi - di * mi;
    bool found = true;
    for (int j = 0; j < N; j++) {
      if (j == i) continue;
      auto [dj, hj] = ds[j];
      if (dj * mi + bi < hj) {
        found = false;
        break;
      }
    }
    if (found) b = min(b, bi);
  }
  cout << setprecision(17) << b << endl;
  return 0;
}
