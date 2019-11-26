#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <numeric>
typedef std::vector<std::pair<int, int>> pairs;

int improve(std::string& s, pairs& p, pairs& digits, long v, size_t i) {
  char c = s[i];
  pairs::iterator it = std::find_if(p.begin(), p.end(),
      [c](const std::pair<int, int>& p1) {
        return static_cast<char>(p1.second + '0') == c;
      });
  int cost = it->first;
  for (auto d : digits) {
    if (d.second <= (v + cost)) {
      s[i] = d.first + '0';
      // (v + previous digit cost) - new (better) digit cost
      return v + cost - d.second;
    }
  }
  // we didn't change v
  return v;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long v; std::cin >> v;
  pairs a;
  pairs digits;
  for (int i = 1; i <= 9; i++) {
    int t; std::cin >> t;
    a.push_back(std::make_pair(t, i));
    digits.push_back(std::make_pair(i, t));
  }
  std::reverse(digits.begin(), digits.end());
  // sort from cheapest digit to most expensive, then from highest digit to lowest
  std::sort(a.begin(), a.end(), [](const std::pair<int, int>& p1,
                                   const std::pair<int, int>& p2) {
    return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
  });
  std::list<char> number;

  long i = 0;
  for (auto p : a) {
    while (v >= p.first) {
      v -= p.first;
      char digit = p.second + '0';
      if (digit >= (number.empty() ? '0' : number.front()))
        number.push_front(digit);
      else
        number.push_back(digit);
      i++;
    }
  }
  std::string n(number.begin(), number.end());
  if (v) {
    long i = 0;
    long len = number.size();
    while (i < len && v) {
      v = improve(n, a, digits, v, i);
      i++;
    }
  }
  std::cout << (n.empty() ? "-1" : n) << '\n';
  return 0;
}
