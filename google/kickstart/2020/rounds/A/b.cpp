#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  int t = T;
  while (t--) {
    int n, k, p; cin >> n >> k >> p;
    vector<vector<int>> sums;

    for (int i = 0; i < n; i++) {
      vector<int> sum;
      int s = 0;
      for (int j = 0; j < k; j++) {
        int v; cin >> v;
        s += v;
        sum.push_back(s);
      }
      sums.push_back(sum);
    }

    vector<vector<pair<int, int>> sums_up_to;

    unordered_set<int> whole_stacks_used;
    vector<pair<int, int>> max_sums;
    for (int i = 0; i < n; i++)
      max_sums.push_back({sums[i][k - 1], i});

    sort(begin(max_sums), end(max_sums), greater<pair<int, int>>());
    int total = 0;
    int whole_stacks = p / k;

    for (int i = 0; i < whole_stacks; i++) {
      auto [max_sum, col_index] = max_sums[i];
      whole_stacks_used.insert(col_index);
      total += max_sum;
    }
    int rem = p % k;
    if (rem) {
      int max_col = 0;
      for (int i = 0; i < n; i++) {
        if (whole_stacks_used.count(i)) continue;
        max_col = std::max(sums[i][rem - 1], max_col);
      }
      total += max_col;
    }
    cout << "Case #" << (T - t) << ": " << total << endl;
  }

  return 0;
}
