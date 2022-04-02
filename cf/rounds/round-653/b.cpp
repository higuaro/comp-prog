#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n != 1 && n % 3 != 0) {
      cout << -1 << endl;
      continue;
    }
    unordered_set<int> seen;
    int steps = 0;
    while (n != 1) {
      if (seen.count(n)) {
        steps = -1;
        break;
      }
      seen.insert(n);
      if (n % 6 == 0) {
        n /= 6;
      } else {
        n *= 2;
      }
      steps++;
    }
    cout << steps << endl;
  }
  return 0;
}
