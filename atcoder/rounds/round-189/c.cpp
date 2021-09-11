#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  unordered_map<int, int> idx;
  int index = 0;
  for (int ai : s) idx[ai] = index++;
  vector<vector<int>> aa(s.size(), vector<int>(n, 0));
  for (int i = 0; i < n; i++) {

  }

  return 0;
}
