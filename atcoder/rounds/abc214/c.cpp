#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<uint64_t, int>> s;
  vector<pair<uint64_t, int>> t;
  for (int i = 0; i < n; i++) {
    uint64_t si; cin >> si; s.push_back({si, i});
  }
  for (int i = 0; i < n; i++) {
    uint64_t ti; cin >> ti; t.push_back({ti, i});
  }

  auto m = *std::min_element(begin(t), end(t), [](auto& p1, auto& p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
  });
  set<int> starters;
  int solved = 0;
  vector<uint64_t> sol(n, 0);

  for (int i = 0; i < n; i++) {
    if (s[i].first == m.first) {
      starters.insert(i);
      solved++;
      sol[i] = m.first;
    }
  }

  vector<uint64_t> sum(n + 1, 0);
  partial_sum(begin(s), end(s), begin(sum));
  const uint64_t oo = numeric_limits<uint64_t>::max();
  for (int i = 0; i < n; i++) {
    if (sol[i]) continue;
    // Find closest starter
    auto next = starters.upper_bound(i);
    int i_next = next != starters.end() ? *next : 0;
    int i_prev = -1;
    if (starters.size() > 1) 
      i_prev = *--next;
    else 
      i_prev = *starters.begin() < i ? *starters.begin() : -1;

    uint64_t sum_next = i_next != -1 ? sum[i_next + 1] - sum[i + 1] : oo;
    uint64_t sum_prev = i_prev != -1 ? sum[i + 1] - sum[i_prev + 1] : oo;
  }

  return 0;
}
