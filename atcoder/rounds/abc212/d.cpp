#include <bits/stdc++.h>
using namespace std;
int main() {
  int q; cin >> q; 
  vector<pair<int, int>> qs(q, {0, 0});
  for (int i = 0; i < q; i++) {
    int pi, xi = 0;
    cin >> pi;
    if (pi < 3) cin >> xi;
    qs[i] = {pi, xi};
  }
  return 0;
}
