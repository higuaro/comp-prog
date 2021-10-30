#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  unordered_map<int, int> edges;
  for (int i = 0; i < n; i++) {
    int ai, bi; cin >> ai >> bi;
    edges[ai]++;
    edges[bi]++;
  }
  for (auto [edge, count] : edges) {
    if (count >= n) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
