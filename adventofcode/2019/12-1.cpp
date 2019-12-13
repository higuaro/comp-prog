#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<array<int, 3>> pos;
  vector<array<int, 3>> vels;

  int x, y, z;
  while (scanf("<x=%d, y=%d, z=%d>\n", &x, &y, &z) != EOF) {
    pos.push_back({x, y, z});
    vels.push_back({0, 0, 0});
  }

  const int steps = 1000;
  for (int step = 0; step < steps; step++) {
    for (size_t i = 0; i < pos.size(); i++) {
      auto& a = pos[i];
      auto& va = vels[i];
      for (size_t j = 0; j < pos.size(); j++) {
        if (i == j) continue;
        auto b = pos[j];
        for (int k = 0; k < 3; k++)
          va[k] += (a[k] < b[k] ? 1 : (a[k] > b[k] ? -1 : 0));
      }
    }

    for (size_t i = 0; i < pos.size(); i++)
      for (size_t k = 0; k < 3; k++)
        pos[i][k] += vels[i][k];
  }

  int e = 0, ke, pe;
  for (size_t i = 0; i < pos.size(); i++) {
    pe = ke = 0;
    for (size_t k = 0; k < 3; k++) {
      pe += abs(pos[i][k]);
      ke += abs(vels[i][k]);
    }
    e += pe * ke;
  }
  cout << e << endl;

  return 0;
}
