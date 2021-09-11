#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, d; cin >> n >> s >> d;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    if (x < s && y > d) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
