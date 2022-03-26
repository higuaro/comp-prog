#include <bits/stdc++.h>
using namespace std;
const uint64_t M = 1e9;
int main() {
  int n; cin >> n;
  int zeros = 0;
  while (n) {
    n /= 5;
    zeros += n;
  }
  cout << zeros << endl;
  return 0;
}
