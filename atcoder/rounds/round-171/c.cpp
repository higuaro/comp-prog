#include <bits/stdc++.h>
using namespace std;
string name(uint64_t n) {
  ostringstream oss;
  const uint64_t B = 26ULL;
  while (n) {
    n--;
    uint64_t d = n % B;
    oss << static_cast<char>(d + 'a');
    n /= B;
  }
  string s = oss.str();
  reverse(begin(s), end(s));
  return s;
}
int main() {
  uint64_t n; cin >> n;
  cout << name(n) << endl;
  return 0;
}
