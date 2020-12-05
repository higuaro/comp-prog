#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
int main() {
  vector<string> m;
  string line;
  while (getline(cin, line, '\n')) 
    m.push_back(line);
  int w = m[0].size();
  int h = m.size();
  int x, y; x = y = 0;
  int t = 0;
  while (y < h) {
    if (m[y][x] == '#') t++;
    x = (x + 3) % w;
    y++;
  }
  cout << t << endl;
  return 0;
}
