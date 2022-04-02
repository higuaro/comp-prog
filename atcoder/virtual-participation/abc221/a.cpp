#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  // cout << ("" ? "" : "") << endl;
  // cout << (? : ) << endl;
  cout << ((uint64_t) pow(32, abs(a- b))) << endl;
  return 0;
}
