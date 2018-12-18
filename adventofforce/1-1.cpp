#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef int64_t ll;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll total = 0;
  ll tmp;
  while (cin >> tmp) {
    total += tmp;
  }
  cout << total << std::endl;
  return 0;
}
