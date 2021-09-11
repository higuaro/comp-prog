#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  cout << (n < 126 ? 4 : (n >= 212 ? 8 : 6)) << endl;
  return 0;
}
