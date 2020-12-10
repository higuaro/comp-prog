#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int id = 0;
  while (getline(cin, s, '\n')) {
    int lr = 0, hr = 127;
    int lc = 0, hc = 7;
    for (auto c : s) {
      int dr = (hr - lr) / 2;
      int dc = (hc - lc) / 2;
      switch (c) {
        case 'F': hr = lr + dr; break;
        case 'B': lr = hr - dr; break;
        case 'L': hc = lc + dc; break;
        case 'R': lc = hc - dc; break;
      }
    }
    id = max(id, lr * 8 + lc);
  }
  cout << id << endl;
  return 0;
}
