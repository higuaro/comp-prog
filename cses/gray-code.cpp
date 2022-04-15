#include <bits/stdc++.h>
using namespace std;
string to_bin(int n, uint64_t k) {
  string s;
  while (k) {
    s += static_cast<char>((k % 2) + '0');
    k /= 2;
  }
  while (s.size() < n) s += '0';
  reverse(begin(s), end(s));
  return s;
}
int main() {
  int n; cin >> n;
  uint64_t nn = 1 << n;
  for (uint64_t k = 0; k < nn; k++) 
    cout << to_bin(n, k ^ (k >> 1)) << endl;
  return 0;
}
