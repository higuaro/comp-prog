#include <bits/stdc++.h>
using namespace std;
uint64_t lcm(uint64_t a, uint64_t b) {
  return (a * b) / __gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<array<int, 3>> pos;
  vector<array<int, 3>> vels;

  array<set<array<int, 8>>, 3> axis_states;
  array<uint64_t, 3> axis_cycle; axis_cycle.fill(0);
  int cycles_found = 0;

  int x, y, z;
  while (scanf("<x=%d, y=%d, z=%d>\n", &x, &y, &z) != EOF) {
    pos.push_back({x, y, z});
    vels.push_back({0, 0, 0});
  }

  for (int64_t step = 0; ; step++) {
    if (cycles_found == 3) break;
    for (size_t axis = 0; axis < 3; axis++) {
      if (axis_cycle[axis]) continue;
      array<int, 8> axis_state;
      for (size_t i = 0; i < pos.size(); i++) {
        axis_state[2 * i] = pos[i][axis];
        axis_state[2 * i + 1] = vels[i][axis];
      }
      if (axis_states[axis].count(axis_state)) {
        axis_cycle[axis] = axis_states[axis].size();
        cycles_found++;
      } else
        axis_states[axis].insert(axis_state);
    }

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

  uint64_t steps = lcm(axis_cycle[0], lcm(axis_cycle[1], axis_cycle[2]));
  cout << steps << endl;

  return 0;
}
