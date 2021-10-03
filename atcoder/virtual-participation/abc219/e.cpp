#include <bits/stdc++.h>
using namespace std;

void d(int mat[4][4], int m) {
  cout << "------- " << bitset<16>(m) << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) 
      cout << mat[i][j];
    cout << endl;
  }
}

int bfs_count(queue<pair<int, int>>& q, int mat[4][4]) {
  set<pair<int, int>> seen;
  int o[5] = {-1, 0, 1, 0, -1};
  auto [i, j] = q.front();
  int x = mat[i][j];
  while (!q.empty()) {
    auto [i, j] = q.front(); q.pop();
    seen.insert({i, j});
    for (int k = 0; k < 4; k++) {
      int ii = i + o[k];
      int jj = j + o[k + 1];
      if (0 <= ii && ii < 4 && 0 <= jj && jj < 4 
          && mat[ii][jj] == x 
          && !seen.count({ii, jj}))
        q.push({ii, jj});
    }
  }
  return seen.size();
}

bool is_valid(int m, int bits) {
  int mat[4][4];
  int m_bits = 0;
  queue<pair<int, int>> q1;
  queue<pair<int, int>> q0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      mat[i][j] = (m >> ((3 - i) * 4 + 3 - j)) & 1;
      if (mat[i][j]) m_bits++;
      if (mat[i][j] && q1.empty()) q1.push({i, j});
      if (!mat[i][j] && q0.empty()) q0.push({i, j});
    }

  bool v = bfs_count(q1, mat) == m_bits && bfs_count(q0, mat) == 16 - m_bits;

if (v) d(mat, m);

  return v;
}

int main() {
  int m = 0;
  for (int i = 0; i < 16; i++) {
    int mi; cin >> mi;
    m |= mi << (15 - i);
  }
  int bits = __builtin_popcount(m);
  int t = 0;
  for (int k = 0; k < 65535; k++) {
    if (__builtin_popcount(m & k) != bits) continue;
    if (bits == 1 || is_valid(k, bits)) t++;
  }
  cout << t << endl;
}
