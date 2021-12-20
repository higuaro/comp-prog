#include <bits/stdc++.h>
using namespace std;
const int oo = numeric_limits<int>::max();
int x_min = 20;
int x_max = 30;
int y_min = -10;
int y_max = -5;
//int x_min = 102;
//int x_max = 157;
//int y_min = -146;
//int y_max = -90;
int hits = 0;
int simulate(int vx, int vy) {
  const int _vx = vx;
  const int _vy = vy;
  int x = 0, y = 0;
  int max_h = -oo;
  if (vx == 6 && vy == 0) 
    cout << 'h';
  if (vx == 7 && vy == -1) 
    cout << 'o';
  while (x <= x_max && y >= y_max) {
    x += vx;
    y += vy;
    max_h = max(max_h, y);
    if (x_min <= x && x <= x_max && y_min <= y && y <= y_max) {
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
