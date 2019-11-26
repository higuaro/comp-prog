#include <iostream>
#include <iomanip>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  double a, b, c, d;
  std::cin >> a >> b >> c >> d;
  double p1 = a / b;
  double p2 = c / d;
  double np1 = 1 - p1;
  double np2 = 1 - p2;
  std::cout << std::setprecision(12) << (p1 / (1 - np1 * np2)) << '\n';
  return 0;
}
