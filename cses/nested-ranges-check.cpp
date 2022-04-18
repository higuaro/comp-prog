#include <bits/stdc++.h>
using namespace std;
const int oo = numeric_limits<int>::max();
typedef tuple<int, int, int> seg_t;
int main() {
  int n; cin >> n;
  vector<bool> contains(n, false);
  vector<bool> is_contained(n, false);
  vector<seg_t> segs;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    segs.push_back({a, b, i});
  }
  auto cmp1 = [](const seg_t& p1, const seg_t& p2) {
    auto [a1, b1, i1] = p1;
    auto [a2, b2, i2] = p2;
    return a1 != a2 ? a1 < a2 : b1 > b2;
  };
  sort(begin(segs), end(segs), cmp1);
  int max_r = 0;
  for (const auto& [l, r, i] : segs) {
    if (r <= max_r)
      is_contained[i] = true;
    max_r = max(max_r, r);
  }
  auto cmp2 = [](const seg_t& p1, const seg_t& p2) {
    auto [a1, b1, i1] = p1;
    auto [a2, b2, i2] = p2;
    return a1 != a2 ? a1 > a2 : b1 < b2;
  };
  sort(begin(segs), end(segs), cmp2);
  int min_r = oo;
  for (const auto& [l, r, i] : segs) {
    if (r >= min_r) 
      contains[i] = true;
    min_r = min(min_r, r);
  }
  for (auto c : contains)
    cout << c << ' '; 
  cout << '\n';
  for (auto c : is_contained)
    cout << c << ' '; 
  cout << '\n';
  return 0;
}
