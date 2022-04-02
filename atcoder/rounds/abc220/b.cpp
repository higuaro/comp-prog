#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ull;
ull to_dec(const string& s, int b) {
  ull k = 0;
  ull bb = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    size_t d = s[i] - '0';
    k += bb * d;
    bb *= b;
  }
  return k;
}
int main() {
  int k; cin >> k;
  string a, b; cin >> a >> b;
  cout << (to_dec(a, k) * to_dec(b, k)) << endl;
  return 0;
}
