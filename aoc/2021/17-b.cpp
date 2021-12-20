#include <iostream>
#include <cmath>
using namespace std;
const int oo = numeric_limits<int>::max();
//int x_min = 20;
//int x_max = 30;
//int y_min = -5;
//int y_max = -10;
int x_min = 102;
int x_max = 157;
int y_min = -90;
int y_max = -146;
int hits = 0;
int simulate(int vx, int vy) {
  const int _vx = vx;
  const int _vy = vy;
  int x = 0, y = 0;
  int max_h = -oo;
  bool debug = (vx == 6 && vy == 0);
  while (x <= x_max && y >= y_max) {
    x += vx;
    y += vy;
    if (debug) cout << vx <<','<< vy<<':'<<x << ',' << y<< endl;
    max_h = max(max_h, y);
    if (debug)
      cout << "c: " << (x_min <= x && x <= x_max && y_min <= y && y <= y_max) << endl;
    if (x_min <= x && x <= x_max && y_max <= y && y <= y_min) {
      cout << _vx << ',' << _vy << " -- " << x << ',' << y <<  endl;
      hits++;
      return max_h;
    }
    if (vx != 0)
      vx += (vx > 0 ? -1 : 1);
    vy--;
  }
  return -oo;
}
int main() {
  int max_h = -oo;
  for (int vx = 0; vx <= 500; vx++) {
    for (int vy = -1000; vy <= 1000; vy++) {
      max_h = max(max_h, simulate(vx, vy));
    }
  }
  cout << max_h << endl;
  cout << hits << endl;
  return 0;
}
