#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> voxel_t;
bool is_active(const set<voxel_t>& voxels, voxel_t voxel) {
  auto [vx, vy, vz] = voxel;
  int neighbours = 0;
  bool active = voxels.count(voxel);
  for (int z = vz - 1; z <= vz + 1; z++) {
    for (int y = vy - 1; y <= vy + 1; y++) {
      for (int x = vx - 1; x <= vx + 1; x++) {
        if (x == vx && y == vy && z == vz) continue;
        if (voxels.count({x, y, z}))
          neighbours++;
      }
    }
  }
  return active
    ? neighbours == 2 || neighbours == 3
    : neighbours == 3;
}
int main() {
  int min_x, max_x;
  int min_y, max_y;
  int min_z, max_z;
  min_x = min_y = min_z = 0;
  max_x = max_y = max_z = 0;
  set<voxel_t> voxels;
  string line;
  while (getline(cin, line, '\n')) {
    int line_size = line.size();
    max_x = max(max_x, line_size);
    for (int x = 0; x < line_size; x++)
      if (line[x] == '#')
        voxels.insert({x, max_y, 0});
    max_y++;
  }

  int cycles = 0;
  const int max_cycles = 6;
  while (cycles++ < max_cycles) {
    set<voxel_t> new_voxels;
    for (int x = min_x - 2; x <= max_x + 2; x++) {
      for (int y = min_y - 2; y <= max_y + 2; y++) {
        for (int z = min_z - 2; z <= max_z + 2; z++) {
          voxel_t voxel = {x, y, z};
          if (is_active(voxels, voxel)) {
            new_voxels.insert(voxel);
            min_x = min(min_x, x); max_x = max(max_x, x);
            min_y = min(min_y, y); max_y = max(max_y, y);
            min_z = min(min_z, z); max_z = max(max_z, z);
          }
        }
      }
    }
    voxels = new_voxels;
  }
  cout << voxels.size() << endl;
  return 0;
}
