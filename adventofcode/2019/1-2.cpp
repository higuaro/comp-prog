#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  uint64_t total = 0;
  uint mass;
  while (cin >> mass) {
    int64_t fuel = mass;
    do {
      fuel = (fuel / 3) - 2;
    } while (fuel > 0 && (total += fuel));
  }
  cout << total << endl;
  return 0;
}
