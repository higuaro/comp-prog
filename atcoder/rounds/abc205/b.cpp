#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  unordered_set<int> seen;
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    if (ai > n || seen.count(ai)) {
      cout << "No" << endl;
      return 0;
    }
    seen.insert(ai);
  }

  cout << "Yes" << endl;
  return 0;
}
