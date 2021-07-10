#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  cout << (n / 100) + ((n % 100) ? 1 : 0) << endl;
  return 0;
}

