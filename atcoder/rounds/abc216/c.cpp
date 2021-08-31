#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t n; cin >> n;
  ostringstream oss;
  while (n) {
    if (n & 1) oss << 'A';
    oss << 'B';
    n >>= 1;
  }
  auto s = oss.str();
  reverse(begin(s), end(s));
  if (s[0] == 'B') s = s.substr(1, s.size() - 1);
  cout << s << endl;
  return 0;
}
