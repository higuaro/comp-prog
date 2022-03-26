#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x; cin >> n >> x;
  multiset<int, greater<int>> p;
  for (int i = 0; i < n; i++) {
    int pi; cin >> pi;
    p.insert(pi);
  }
  int total = 0;
  while (!p.empty()) {
    auto p1 = p.begin();
    int w = *p1;
    p.erase(p1);
    if (w > x) continue;
    auto p2 = p.lower_bound(x - w); 
    if (p2 != p.end())
      p.erase(p2);
    total++;
  }
  cout << total << endl;
  return 0;
}
