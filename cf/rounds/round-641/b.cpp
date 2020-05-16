#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> s;
    vector<int> memo;
    for (int i = 0; i < n; i++) {
      int si; cin >> si;
      s.push_back(si);
      memo.push_back(1);
    }

    for (int i = 0; i <= n / 2; i++) {
      int k = i + 1;
      for (int q = 2 * k; q <= n; q += k) {
        if (s[k - 1] < s[q - 1]) {
          memo[q - 1] = max(memo[q - 1], memo[k - 1] + 1);
        }
      }
    }

    cout << *max_element(begin(memo), end(memo)) << endl;
  }
  return 0;
}
