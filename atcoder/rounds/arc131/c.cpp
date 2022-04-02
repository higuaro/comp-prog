#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  if (n == 1) {
    cout << "Win" << endl;
    return 0;
  } else if (n == 2) {
    cout << "Loose" << endl;
    return 0;
  }
  vector<int> a(n, 0);
  int xor_a = 0;
  for (auto& ai : a) {
    cin >> ai;
    xor_a ^= ai;
  }
  if (__builtin_popcount(xor_a) & 1) {
    cout << "Loose" << endl;
  } else {
    cout << "Win" << endl;
  }
  
  return 0;
}
