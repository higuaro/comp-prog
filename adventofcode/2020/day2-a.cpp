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
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; i++) 
      if (s[i] == c) count++;
    valid += (a <= count && count <= b ? 1 : 0);
  }
  cout << valid << endl;
  return 0;
}
