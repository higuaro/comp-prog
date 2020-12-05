#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
  string line;
  int valid = 0;
  while (getline(cin, line, '\n')) {
    int a, b; char c, s[256];
    sscanf(line.c_str(), "%d-%d %c: %s\n", &a, &b, &c, s);
    valid += ((s[a - 1] == c) ^ (s[b - 1] == c) ? 1 : 0);
  }
  cout << valid << endl;
  return 0;
}
