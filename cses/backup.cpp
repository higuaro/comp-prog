#include <bits/stdc++.h>
using namespace std;
int64_t pow10(int k) {
  int64_t r = 1;
  for (int i = 0; i < k; i++) r *= 10;
  return r;
}
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t q; cin >> q;
    int num_digits = log10(q) + 1;
    // last n - 1 digits number
    int64_t base = pow10(num_digits - 1) - 1;
    int64_t number_index = q - base;
    int64_t number = base + (number_index / num_digits);
    string s = to_string(number);
    reverse(begin(s), end(s));
    int index_within_number = number_index  % num_digits;
    cout << s[index_within_number] << endl;
  }
  return 0;
}
