#include <iostream>
#include <unordered_set>
auto sum_sqr_digits(const unsigned n) -> decltype(n) {
  auto k = n, s = 0u;
  while (k > 0) {
    auto d = k % 10;
    s += d * d;
    k /= 10;
  }
  return s;
}
int main() {
  const unsigned limit = 10000000;
  std::unordered_set<unsigned> ends_in_89;
  std::unordered_set<unsigned> ends_in_1;
  auto n = limit;
  auto count = 0u;
  while (n > 1) {
    unsigned k = n;
    std::unordered_set<unsigned> chain;
    while (k != 1 && k != 89) {
      chain.insert(k);
      k = sum_sqr_digits(k);
      if (ends_in_1.count(k)) {
        k = 1; break;
      }
      if (ends_in_89.count(k)) {
        k = 89; break;
      }
    }
    if (k == 1)
      ends_in_1.insert(chain.begin(), chain.end());
    else {
      ends_in_89.insert(chain.begin(), chain.end());
      count++;
    }
    n--;
  }
  std::cout << count << std::endl;
  return 0;
}
