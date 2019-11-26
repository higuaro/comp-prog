#include <iostream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n, k; std::cin >> n >> k;
  std::vector<size_t> scores;
  std::copy(std::istream_iterator<size_t>(std::cin), 
      std::istream_iterator<size_t>(), 
      std::back_inserter(scores));
  size_t total = 0;
  size_t max = 0;
  for (auto s : scores) {
    if (s && s >= max) total++;
    if (total == k) max = s;
  }
  std::cout << total << '\n';
  return 0;
}
