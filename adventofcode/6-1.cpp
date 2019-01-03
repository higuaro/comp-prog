#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tx, ty; char _;
  vector<pair<int, int>> coords {};
  while (cin >> tx >> _ >> ty)
    coords.push_back(make_pair(tx, ty));
  for (auto [x, y] : coords) {
    cout << x << ", " << y << endl;
  }
  return 0;
}
