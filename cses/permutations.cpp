#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n; cin >> n;
  if (n == 1) {
    cout << "1\n"; 
    return 0;
  }
  if (n < 4) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  if (n == 4) {
    cout << "2 4 1 3\n" << endl;
    return 0;
  }

  int max_even = (n & 1) ? n - 1 : n;
  int max_odd = (n & 1) ? n : n - 1;
  for (int k = max_even; k >= 2; k -= 2)
    cout << k << ' ';
  for (int k = max_odd; k >= 1; k -= 2)
    cout << k << ' ';
  cout << '\n';
  return 0;
}
