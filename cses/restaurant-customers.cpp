#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<int, bool>> events;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    events.push_back({a, true});
    events.push_back({b, false});
  }
  sort(events.begin(), events.end());
  int max_customers = 0;
  int c = 0;
  for (const auto [_, arrived] : events) {
    c += (arrived ? 1 : -1);
    max_customers = max(max_customers, c);
  }
  cout << max_customers << endl;

  return 0;
}
