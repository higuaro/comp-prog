#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  uint64_t total = 0;
  uint mass;
  while (cin >> mass) {
    total += (mass / 3) - 2;
  }
  cout << total << endl;
  return 0;
}
