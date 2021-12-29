#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> seats;
  string s;
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
    seats.push_back(lr * 8 + lc);
  }
  sort(begin(seats), end(seats));
  for (int i = 1; i < static_cast<int>(seats.size()); i++) {
    if (seats[i] - seats[i - 1] > 1) {
      cout << seats[i - 1] + 1 << endl;
      return 0;
    }
  }
  return 0;
}
