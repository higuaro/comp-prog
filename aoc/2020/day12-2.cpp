#include <bits/stdc++.h>
using namespace std;
pair<int, int> angle_to_dir(const int ang, int wx, int wy) {
  int a = ang < 0 ? 360 + ang : ang;
  int steps = a / 90;
  while (steps--) {
    swap(wx, wy);
    wx *= -1;
  }
  return {wx, wy};
}
int main() {
  int wx = 10, wy = 1;
  int ship_x = 0, ship_y = 0;
  string line;
  while (cin >> line) {
    char a = line[0];
    int v = stoi(line.substr(1));
    switch (a) {
      case 'N': wy += v; break;
      case 'S': wy -= v; break;
      case 'E': wx += v; break;
      case 'W': wx -= v; break;
      case 'L':
      case 'R': {
          auto [wx2, wy2] = angle_to_dir(a == 'L' ? v : -v, wx, wy);
          wx = wx2; wy = wy2;
        }
        break;
      case 'F':
        ship_x += v * wx;
        ship_y += v * wy;
        break;
    }
  }
  cout << abs(ship_x) + abs(ship_y) << endl;
  return 0;
}
