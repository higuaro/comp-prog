#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, t; cin >> n >> x >> t;
  cout << static_cast<int>(ceil(n / static_cast<float>(x)) * t) << endl;
  return 0;
}
