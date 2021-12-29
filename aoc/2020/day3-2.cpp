#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
struct slope {
  int x, y;
  int ox, oy;
  int t;
  slope(int ox, int oy) : x(0), y(0), ox(ox), oy(oy), t(0) {}
};
int main() {
  vector<string> m;
  string line;
  while (getline(cin, line, '\n')) 
    m.push_back(line);
  int w = m[0].size();
  int h = m.size();
  vector<slope> slopes { {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2} };
  bool keep_going = true;
  while (keep_going) {
    keep_going = false;
    int s = 0;
    for (auto& slope : slopes) {
      if (slope.y < h) {
        if (m[slope.y][slope.x] == '#')
          slope.t++;
        keep_going = true;
      }
      slope.x = (slope.x + slope.ox) % w;
      slope.y += slope.oy;
      s++;
    }
  }
  uint64_t p = 1ULL;
  for (auto& slope : slopes) {
    cout << slope.t << endl;
    p *= slope.t;
  }
  cout << p << endl;
  return 0;
}
