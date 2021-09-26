#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
int sum(ll n) {
  int r = 0;
  while (n) {
    r += n % 10;
    n /= 10;
  }
  return r;
}
ll solve(const int K) {
  int k = 0;
  int n = 0;
  while (k < K) {
    int s = sum(++n);
    if (s == 10) k++;
  }
  return n;
}
int main() {
  int k; cin >> k;
  cout << solve(k) << endl;
  return 0;
}
