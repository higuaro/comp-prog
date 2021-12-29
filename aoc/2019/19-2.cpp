#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
int find_square(array<pair<int, int>, 100>& ranges, int y) {
  int max_start = 0;
  int min_end = 1e5;
  for (int i = 0; i < 100; i++) {
    auto [start, end] = ranges[(y + 1 + i) % 100];
    if (start > max_start) max_start = start;
    if (end < min_end) min_end = end;
  }
  return min_end - max_start >= 100
      ? 10000 * max_start + (y - 99)
      : -1;
}
int main() {
  ifstream program("19.in");
  auto rom = intcode::parse_rom(program);

  const int W = 1e5;
  array<pair<int, int>, 100> ranges;

  for (int y = 200; ; y++) {
    int start = 0, end = 0;
    bool first_found = false, last_found = false;

    for (int x = 0; x < W; x++) {
      int count = 0;
      intcode machine{
        rom,
        [&]() {
          return count++ ? y : x;
        },
        [&](int64_t v) {
          if (v) {
            if (!first_found) {
              first_found = true;
              start = x;
            }
          } else {
            if (first_found) {
              last_found = true;
              end = x;
            }
          }
        }
      };
      machine.run();
      if (last_found) {
        ranges[y % 100] = {start, end};
        if (y >= 99) {
          auto closest = find_square(ranges, y);
          if (closest != -1) {
            cout << closest << endl;
            return 0;
          }
        }
        break;
      }
    }
  }
  return 0;
}
