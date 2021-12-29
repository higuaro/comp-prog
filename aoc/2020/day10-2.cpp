#include <bits/stdc++.h>
using namespace std;
unordered_map<int, uint64_t> memo;
int64_t solve(const vector<int>& js, const int n, int i = 0) {
  if (memo[i]) return memo[i];
  if (i == n - 1) return 1;
  uint64_t total = 0LL;
  for (int k = i + 1; k <= min(i + 3, n - 1); k++) {
    if (js[k] - js[i] <= 3)
      total += solve(js, n, k);
    else
      break;
  }
  return memo[i] = total;
}
int main() {
  vector<int> js{0};
  int jolt; while (cin >> jolt) js.push_back(jolt);
  sort(begin(js), end(js));
  js.push_back(js.back() + 3);
  cout << solve(js, js.size()) << endl;
  return 0;
}
