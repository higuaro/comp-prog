#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, bool, int> event_t;
int main() {
  int n; cin >> n;
  vector<bool> contains(n, false);
  vector<bool> contained(n, false);
  vector<event_t> events;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    events.push_back({a, i, true});
    events.push_back({b, i, false}); 
  }
  sort(begin(events), end(events));

  set<int> active_segs;
  for (auto [xi, open, i] : events) {
    if (open) 
      active_segs.insert(i);
    
  }
  return 0;
}
