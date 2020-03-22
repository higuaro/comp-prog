#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    b.push_back(v);
  }

  int max = b[0];
  vector<int> a;
  a.push_back(max);
  for (int i = 1; i < n; i++) {
    int ai = max + b[i];
    max = std::max(max, ai);
    a.push_back(ai);
  }
  bool first = true;
  for (auto ai : a) {
    if (!first) cout << ' ';
    cout << ai;
    first = false;
  }
  cout << endl;
  return 0;
}
