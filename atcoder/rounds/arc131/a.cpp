#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a, b; cin >> a >> b;
  if (a * 2 == b) {
    cout << a << endl;
    return 0;
  }
  cout << a;
  cout << (b / 2);
  if (b & 1) cout << 5;
  cout << endl;
  return 0;
}
