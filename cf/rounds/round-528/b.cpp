#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  int k; cin >> k;

  vector<pair<int, int>> pairs;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) { 
      pairs.push_back(make_pair(i, n / i));
      pairs.push_back(make_pair(n / i, i));
    }
  }
  int m = numeric_limits<int>::max();
  for (auto p : pairs) {
    if (p.second >= k) continue;
    int x = p.first * k + p.second;
    if (x < m) m = x;
  }
  cout << m << std::endl;
  return 0;
}
