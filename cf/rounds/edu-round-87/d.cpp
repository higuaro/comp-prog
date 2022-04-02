#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q; cin >> n >> q;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    a.push_back(ai);
  }
  sort(begin(a), end(a));
  vector<pair<int, int>> ca;
  int prev = a[0];
  int count = 1;
  for (int i = 1; i < n; i++) {
    int ai = a[i];
    if (ai == prev) {
      count++;
    } else {
      ca.emplace_back(prev, count);
      prev = ai;
      count = 1;
    }
  }
  a.clear();
  ca.emplace_back(prev, count);

  while (q--) {
    int k; cin >> k;
    if (k > 0) {
      
    }
  }
  return 0;
}
