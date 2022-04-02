#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int x, y, z; cin >> x >> y >> z;
  if (x == y) {
    if (z) {
      cout << '?' << endl; return 0;
    } else {
      cout << '0' << endl; return 0;
    }
  }
  bool up = x + z > y;
  bool down = y + z > x;
  bool tie = x + z == y || y + z == x;
  int pos_results = (up ? 1 : 0) + (down ? 1 : 0) + (tie ? 1 : 0);
  if (pos_results > 1) {
    cout << '?' << endl; return 0;
  }
  if (up)
    cout << '+';
  else if (down)
    cout << '-';
  else
    cout << '0';
  cout << endl;
  return 0;
}
