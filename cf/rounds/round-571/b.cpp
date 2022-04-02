#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ul;
ul solve(ul w, ul h) {
  ul v_rods = (w + (w & 1)) / 2;
  ul num_v_rods = (h - (h / 3)) / 2;
  ul total = v_rods * num_v_rods;
  ul taken_spaces = num_v_rods * 2;
  ul in_between_spaces = (num_v_rods + (num_v_rods & 1)) / 2;
  ul rem = std::min(static_cast<ul>(0), h - taken_spaces - in_between_spaces);
  if (rem >= 2) {
    ul num_h_rods = (w - (w / 3)) / 2;
    total += num_h_rods;
  }
  return total;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ul n, m; cin >> n >> m;
  ul r0 = solve(n, m);
  ul r1 = solve(m, n);
  cout << max(r0, r1) << endl;
  return 0;
}
