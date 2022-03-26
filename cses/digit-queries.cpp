#include <bits/stdc++.h>
using namespace std;
int64_t pow10(int k) {
  int64_t r = 1;
  for (int i = 0; i < k; i++) r *= 10;
  return r;
}
int64_t mod(int64_t k, int64_t n) {
  return ((k % n) + n) % n;
}
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t q; cin >> q;
    int64_t num_digits = 0;
    int64_t digits_used = 0;
    while (true) {
      int64_t k = pow10(num_digits) * 9 * (num_digits + 1);
      if (digits_used + k >= q) break;
      digits_used += k;
      num_digits++;
    }
    int64_t base = pow10(num_digits) - 1;
    num_digits++;
    int64_t rem_digits = q - digits_used;
    int64_t number = base + (rem_digits / num_digits);
    if (rem_digits % num_digits) number++;
    string s = to_string(number);
    int64_t index_within_number = (rem_digits % num_digits) - 1;
    cout << s[mod(rem_digits - 1, num_digits)] << endl;
  }
  return 0;
}
