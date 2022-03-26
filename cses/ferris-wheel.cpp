#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x; cin >> n >> x;
  vector<int> p(n, 0);
  for (auto& pi : p) cin >> pi;
  sort(begin(p), end(p));
  int total = 0;
  int cur = 0;
  int count = 0;
  for (auto pi : p) {
    if (pi > x) break;
    if (count == 0) {
      count = 1;
      cur = pi;
    } else if (count == 1) {
      total++;
      if (cur + pi <= x) {
        cur = count = 0;
      } else {
        cur = pi;
        count = 1;
      }
    }
  }
  if (cur || count) total++;
  cout << total << endl;
  return 0;
}
