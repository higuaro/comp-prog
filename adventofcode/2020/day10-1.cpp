#include <bits/stdc++.h>
using namespace std;
int solve(const vector<int>& js, const int n,
          int i = 0, int diff = 0) {
  if (i == n - 1)
    return diff + 10000;

  int jolts = js[i];
  for (int j = 1; j < 3; j++) {
    if (i + j >= n) break;

    int jolts_j = js[i + j];
    int d = jolts_j - jolts;
    if (d <= 3) {
      int diff2 = diff + pow(100, d - 1);
      int r = solve(js, n, i + j, diff2);
      if (r) return r;
    } else 
      break;
  }
  return 0;
}
int main() {
  vector<int> jolts;
  int jolt;
  while (cin >> jolt) jolts.push_back(jolt);
  sort(begin(jolts), end(jolts));
  int ans = solve(jolts, jolts.size());
  int d1 = (ans % 100) + 1;
  int d3 = (ans / 10000) % 100;
  cout << d1 * d3 << endl;
  return 0;
}
