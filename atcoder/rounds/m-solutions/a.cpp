#include <bits/stdc++.h>
using namespace std;
int main() {
  int x; cin >> x;
  vector<int> kyu {1800, 1600, 1400, 1200, 1000, 800, 600, 400};
  for (int i = 0; i < kyu.size(); i++) {
    if (x >= kyu[i]) {
      cout << (i + 1) << endl;
      return 0;
    }
  }
  return 0;
}
