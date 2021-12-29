#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
int main() {
  ifstream program("13.in");
  auto rom = intcode::parse_rom(program);

  int count = 0;
  int64_t x, y;
  map<pair<int, int>, int> grid;

  intcode mac{
    rom,
    []() { int64_t v; cin >> v; return v; },
    [&](int64_t v) {
      switch (count) {
        case 0: x = v; break;
        case 1: y = v; break;
        case 2: grid[make_pair(x, y)] = v; break;
      }
      count = (count + 1) % 3;
    }
  };
  mac.run();

  count = 0;
  for (auto e : grid)
    if (e.second == 2) count++;
  cout << count << endl;
  return 0;
}
