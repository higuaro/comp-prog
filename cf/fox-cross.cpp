#include <iostream>
#include <array>
#include <string>
#include <algorithm>
template<typename T, size_t N, size_t M>
using table = std::array<std::array<T, M>, N>;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  table<char, 100, 100> t;
  const char C = '#';
  size_t n; std::cin >> n;
  std::cin.ignore(256, '\n');
  for (size_t i = 0; i < n; i++) {
    std::string line;
    std::getline(std::cin, line);
    for (size_t j = 0; j < n; j++) t[i][j] = line[j];
  }
  for (size_t i = 0; i < n - 2; i++) {
   for (size_t j = 0; j < n - 2; j++) {
      bool broken = false;
      for (size_t k = 0; k < 3; k++) {
        if (t[i + 1][j + k] != C || t[i + k][j + 1] != C) {
          broken = true;
          break;
        }
      }
      if (!broken) 
        for (size_t k = 0; k < 3; k++) 
          t[i + 1][j + k] = t[i + k][j + 1] = '.'; 
    }
  }
  bool good = true;
  for (size_t i = 0; i < n; i++) 
    for (size_t j = 0; j < n; j++) 
      if (t[i][j] == C) { 
        good = false;
        break;
      }
  std::cout << (good ? "YES" : "NO") << '\n';
  return 0;
}
