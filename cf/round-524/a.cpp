#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int books(int sheets, int k) {
  return (sheets / k) + ((sheets % k) ? 1 : 0);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; cin >> n >> k;
  int b = 8 * n;
  int r = 2 * n;
  int g = 5 * n;
  int t = books(b, k) + books(g, k) + books(r, k);
  cout << t << endl;
  return 0;
}
