#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
int main() {
  ifstream f("9.in");
  auto rom = intcode::parse_rom(f);
  intcode mac{rom};
  mac.run();
  return 0;
}
