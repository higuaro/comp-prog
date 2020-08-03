#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d; cin >> n >> d;
  double D = static_cast<double>(d);
  int t = 0;
  for (int i = 0; i < n; i++) {
    int64_t x, y; cin >> x >> y;
    double dd = sqrt(x * x + y * y);
    if (dd <= D) t++;
  }
  cout << t << endl;
  return 0;
}
