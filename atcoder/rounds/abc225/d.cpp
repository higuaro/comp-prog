#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q; cin >> n >> q;
  vector<pair<int, int>> cars(n, {-1, -1});
  while (q--) {
    int qi; cin >> qi;
    switch (qi) {
      case 1: {
        int x, y; cin >> x >> y;
        x--; y--;
        cars[x].second = y;
        cars[y].first = x;
        break;
      }
      case 2: {
        int x, y; cin >> x >> y;
        x--; y--;
        cars[x].second = -1;
        cars[y].first = -1;
        break;
      }
      case 3: {
        int x; cin >> x;
        vector<int> c;
        int xx = cars[--x].first;
        while (xx != -1) {
          c.push_back(xx + 1);
          xx = cars[xx].first;
        }
        reverse(begin(c), end(c));
        c.push_back(x + 1);
        xx = cars[x].second;
        while (xx != -1) {
          c.push_back(xx + 1);
          xx = cars[xx].second;
        }
        cout << c.size() << ' ';
        for (auto ci : c) cout << ci << ' ';
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
