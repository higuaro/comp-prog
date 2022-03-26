#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
  int n, x; cin >> n >> x;
  vector<pii> a;
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    a.push_back({ai, i});
  }
  sort(begin(a), end(a));
  int p1 = -1, p2 = -1;
  for (int i = 0; i < n; i++) {
    if (a[i].first >= x) break;
    int d = x - a[i].first;
    auto aa = lower_bound(a.begin() + i + 1, end(a), make_pair(d, -1),
        [](const pii& p1, const pii& p2) {
          return p1.first < p2.first;
        });
    if (aa != end(a) && aa->first == d) {
      p1 = a[i].second + 1;
      p2 = aa->second + 1;
      break;
    }
  }
  if (p1 == -1)
    cout << "IMPOSSIBLE\n";
   else 
    cout << p1 << ' ' << p2 << '\n';
  return 0;
}
