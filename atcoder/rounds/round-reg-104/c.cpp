#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<int, int>> ab(n, {0, 0});
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    ab[i] = {a > 0 ? a - 1 : a,
             b > 0 ? b - 1 : b};
  }
  sort(begin(ab), end(ab), [](const auto& p1, const auto& p2) {
      if (p1.first == p2.first)
        return p1.second < p2.second;
      return p1.first < p2.first;
  });

  // stupid validations
  vector<int> floor_on(n, 0);
  vector<int> floor_off(n, 0);
  for (int person = 0; person < n; person++) {
    auto [on, off] = ab[person];
    bool invalid = false;
    invalid |= on >= 0 && on >= 0 && on >= off;
    invalid |= on >= 0 && floor_on[on];
    invalid |= off >= 0 && floor_off[off];
    if (invalid) {
      cout << "No" << endl;
      return 0;
    }
    if (on >= 0) floor_on[person] = on;
    if (off >= 0) floor_off[person] = off;
  }

  vector<int> elevator(2 * n, 0);
  for (int person = 0; person < n; person++) {
    auto [on, off] = ab[person];
    if (on < 0 || off < 0) continue;
    for (int k = on; k <= off; k++)
      elevator[k] = person;
  }
  int unknown = 0;
  for (int person = 0; person < n; person++) {
    auto [on, off] = ab[person];
    if (on < 0 && off < 0) {
      unknown++;
    } else if (on < 0) {
      for (int i = 0; i < 2 * n; i++) {
      }
    } else if (off < 0) {
    } else 
      break;
  }
  return 0;
}
