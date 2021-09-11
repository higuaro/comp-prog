#include <bits/stdc++.h>
using namespace std;
int main() {
  int8_t map[2250000];
  memset(map, 0, sizeof map);
  int h, w; cin >> h >> w;
  int n, m; cin >> n >> m;
  vector<pair<int, int>> bulbs(n, {0, 0});
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b; a--; b--;
    bulbs[i] = {a, b};
  }
  for (int i = 0; i < m; i++) {
    int c, d; cin >> c >> d; c--; d--;
    map[c * w + d] = 2;
  }
  int o[] = {-1, 0, 1, 0};
  for (int b = 0; b < n; b++) {
    auto [ii, jj] = bulbs[b];
    map[ii * w + jj] = 1;
    for (int k = 0; k < 4; k++) {
      int oi = o[k];
      int oj = o[(k + 1) % 4];
      int i = ii + oi;
      int j = jj + oj;
      while (0 <= i && i < h && 0 <= j && j < w && map[i * w + j] != 2) {
        map[i * w + j] = 1;
        i += oi;
        j += oj;
      }
    }
  }
  //for (int i = 0; i < h; i++) {
  //  for (int j = 0; j < w; j++) {
  //    cout << static_cast<char>(map[i * w + j] + '0');
  //  }
  //  cout << endl;
  //}
  //cout << endl;

  int count = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (map[i * w + j] == 1) 
        count++;
  cout << count << endl;
  return 0;
}
