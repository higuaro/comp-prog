#include <bits/stdc++.h>
using namespace std;

int change(unordered_map<int, int>& pos, int x) {
  int pos_x = pos[x];
  if (x == 1) {
    const int pos_2 = pos[2];
    return pos_x < pos_2 ? 0 : 1;
  } 
  int pos_pred_x = pos[x - 1];
  return pos_pred_x < pos_x ? 0 : 1;
}

int main() {
  unordered_map<int, int> pos;
  int n, m; cin >> n >> m;
  vector<int> x(n, 0);
  for (int i = 0; i < n; i++) {
    int xi; cin >> xi;
    x[i] = xi;
    pos[xi] = i;
  }
  int runs = 1;
  for (int k = 2; k <= n; k++) 
    if (pos[k - 1] > pos[k]) runs++;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    int xa = x[a], xb = x[b];

    int change_xa = change(pos, xa);
    int change_xb = change(pos, xb);

    swap(x[a], x[b]);
    pos[xa] = b; pos[xb] = a;

    int change_xa_after = change(pos, xa);
    int change_xb_after = change(pos, xb);

    if (change_xa < change_xa_after) 
      runs++;
    else if (change_xa > change_xa_after)
      runs--;

    if (abs(xa - xb) != 1) {
      if (change_xb < change_xb_after) 
        runs++;
      else if (change_xb > change_xb_after)
        runs--;
    }
    
    cout << runs << '\n';
  }
  return 0;
}
