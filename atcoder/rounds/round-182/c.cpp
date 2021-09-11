#include <bits/stdc++.h>
using namespace std;
int s(const string& ss, int mask, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    if ((mask >> i) & 1)
      sum += static_cast<int>(ss[i] - '0');
  return sum;
}
int main() {
  string n; cin >> n;
  const int oo = numeric_limits<int>::max();
  int min_k = oo;
  int l = n.size();
  int max_k = pow(2, l);
  int bits = __builtin_popcount(max_k - 1);
  for (int k = 0; k < max_k; k++) {
    int sum = s(n, k, l);
    if (!(sum % 3))
      min_k = min(min_k, bits - __builtin_popcount(k));
  }
  cout << (min_k == bits || min_k == oo ? -1 : min_k) << endl;
  return 0;
}
