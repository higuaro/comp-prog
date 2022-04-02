#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k; cin >> n >> m >> k;
  cout << (n <= min(m, k) ? "Yes" : "No") << endl;

  return 0;
}
