#include <bits/stdc++.h>
using namespace std;
pair<int, int> angle_to_dir(const int ang) {
  int ox[] = {1, 0, -1, 0};
  int oy[] = {0, -1, 0, 1};
  int steps = (((ang / 90) % 4) + 4) % 4;
  return {ox[steps], oy[steps]};
}
int main() {
  int x = 0, y = 0;
  int ang = 0;
  string line;
  while (cin >> line) {
    char a = line[0];
    int v = stoi(line.substr(1));
    switch (a) {
      case 'N': y -= v; break;
      case 'S': y += v; break;
      case 'E': x += v; break;
      case 'W': x -= v; break;
      case 'L': ang += v; break;
      case 'R': ang -= v; break;
      case 'F':
        auto [dir_x, dir_y] = angle_to_dir(ang);
        x += dir_x * v;
        y += dir_y * v;
        break;
    }
  }
  cout << abs(x) + abs(y) << endl;
  return 0;
}
