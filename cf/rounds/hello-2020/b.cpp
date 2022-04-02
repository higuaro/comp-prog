#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<vector<int>> segs;
  for (int i = 0; i < n; i++) {
    int l; cin >> l;
    vector<int> seg;
    for (int j = 0; j < l; j++) {
      int v; cin >> v;
      seg.push_back(v);
    }
    segs.push_back(seg);
  }

  int total = 0;
  vector<pair<int, int>> maxs;
  vector<pair<int, int>> mins;

  vector<bool> is_asc(segs.size(), false);
  for (int i = 0; i < n; i++) {
    int size = segs[i].size();
    int max = -1, min = 1e9;
    for (int j = 0; j < size; j++) {
      int v = segs[i][j];
      if (v > min) is_asc[i] = true;
      if (v > max) {
        if (max != -1) is_asc[i] = true;
        max = v;
      }
      if (v < min) min = v;
    }
    if (is_asc[i]) total += n;
    mins.push_back({min, i});
    maxs.push_back({max, i});
  }
  sort(begin(mins), end(mins));
  sort(begin(maxs), end(maxs));
  
  for (int i = 0; i < n; i++)
    if (maxs[i] > mins[i]) total += (i + 1);

  cout << total << endl;

  return 0;
}
