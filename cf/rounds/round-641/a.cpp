#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  unordered_map<int, int> memo;
  while (t--) {
    int n, k; cin >> n >> k;
    int r = n;

    if (n & 1) {
      int l = sqrt(n);
      if (!memo.count(n)) {
        int d = n;
        for (int i = 3; i <= l; i += 2) {
          if (!(n % i)) {
            d = i;
            break;
          }
        }
        memo[n] = d;
      }
      r += memo[n] + (k - 1) * 2;
    } else {
      r += k * 2;
    }
    cout << r << endl;
  }
  return 0;
}
