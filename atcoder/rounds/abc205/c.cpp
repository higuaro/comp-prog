#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a, b, c; cin >> a >> b >> c;
  uint64_t abs_a = abs(a);
  uint64_t abs_b = abs(b);
  if (!(c & 1)) 
    cout << (abs_a == abs_b ? "=" : (abs_a > abs_b ? ">" : "<"));
  else
    cout << (a == b ? "=" : (a > b ? ">" : "<"));
  return 0;
}
