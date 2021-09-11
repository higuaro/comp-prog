#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<int, int>> towns;
  uint64_t va = 0ULL;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    towns.push_back({a, b});
    va += a;
  }
  sort(begin(towns), end(towns), 
      [] (const auto& p1, const auto& p2) {
        return p1.first + p1.second > p2.first + p2.second;
      });
  uint64_t vb = 0ULL;
  int i = 0;
  for (; i < n; i++) {
    auto [a, b] = towns[i];
    vb += static_cast<uint64_t>(a) + static_cast<uint64_t>(b);
    if (a > va) va = 0;
    else va -= a;

    if (vb > va) break;
  }
  cout << (i + 1) << endl;

  return 0;
}
