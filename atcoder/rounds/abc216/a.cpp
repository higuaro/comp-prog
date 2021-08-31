#include <bits/stdc++.h>
using namespace std;
int main() {
  double d; cin >> d;
  int xy = static_cast<int>(d * 10);
  int x = xy / 10;
  int y = xy % 10;
  cout << x << (y <= 2 ? "-" : (y >= 7 ? "+" : "")) << endl;
  return 0;
}
