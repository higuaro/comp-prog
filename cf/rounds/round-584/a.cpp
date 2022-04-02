#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n; cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    a.push_back(t);
  }
  sort(a.begin(), a.end());
  set<int> divisors;
  for (int ai : a) {
    if (divisors.empty()) {
      divisors.insert(ai);
      continue;
    }
    bool found = false;
    for (int d : divisors) {
      if (!(ai % d)) {
        found = true;
        break;
      }
    }
    if (!found) {
      divisors.insert(ai);
    }
  }
  cout << divisors.size() << endl;
  return 0;
}
