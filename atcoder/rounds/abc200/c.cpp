#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> m(200, 0);
  uint64_t t = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    int ma = a % 200;
    t += static_cast<uint64_t>(m[ma]);
    m[ma]++;
  }
  cout << t << endl;
  return 0;
}
