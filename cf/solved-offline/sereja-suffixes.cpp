#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  const size_t MAX = 100000;
  std::vector<size_t> a;
  std::array<size_t, MAX> diffs;
  std::unordered_map<size_t, size_t> counts;
  size_t n, m; std::cin >> n >> m;
  for (size_t i = 0; i < n; i++) {
    size_t t; std::cin >> t;
    a.push_back(t);
    counts[t]++;
  }
  size_t t = counts.size();
  std::cout << "t = " << t << '\n';
  for (size_t i = 0; i < n; i++) {
    diffs[i] = t;
    size_t k = a[i];
    counts[k]--;
    if (!counts[k]) t--;
  }
  for (size_t i = 0; i < m; i++) {
    size_t l; std::cin >> l;
    std::cout << diffs[l - 1] << '\n';
  }
  return 0;
}
