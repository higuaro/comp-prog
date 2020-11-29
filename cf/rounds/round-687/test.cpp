#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 1e5;
  cout << n << ' ' << 1 << endl;
  for (int i = 0; i < n; i++) {
    cout << ((i % 100) + 1) << ' ';
  }
  cout << endl;
  return 0;
}
