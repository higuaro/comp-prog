#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  int nn = 1 << n;
  vector<pair<int, int>> t(2 * nn, {0, 0});
  for (int i = 0; i < nn; i++) {
    int ai; cin >> ai;
    t[nn + i] = {ai, i + 1};
  }
  if (n == 1) {
    cout << (t[2].first < t[3].first ? 1 : 2) << endl;
    return 0;
  }

  int offset = t.size();
  for (int level = n; level > 0; level--) {
    int nodes = 1 << level;
    offset -= nodes;
    for (int c = 0; c < nodes; c += 2) {
      t[(offset + c) / 2] = t[offset + c].first > t[offset + c + 1].first 
        ? t[offset + c] : t[offset + c + 1];
    }
  }
for (auto d : t) cerr << '(' << d.first << ',' << d.second << "), "; cerr << endl;
  cout << t[2].second << endl;
  return 0;
}
