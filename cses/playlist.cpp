#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  unordered_map<int, int> pos;
  pos.reserve(2 * n);
  int w = 0;
  int best = -1;
  for (int i = 0; i < n; i++) {
    int ni; cin >> ni;
    if (!pos.count(ni) || i - w > pos[ni]) 
      best = max(++w, best);
    else {
      w = i - pos[ni];
    }
    pos[ni] = i;
  }
  cout << best << '\n';
  return 0;
}
