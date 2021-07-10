#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k; cin >> n >> k;
  vector<pair<int64_t, int>> ids;
  for (int i = 0; i < n; i++) {
    int id; cin >> id; ids.push_back({id, i});
  }
  sort(begin(ids), end(ids));
  vector<int64_t> a(n, k / n);
  for (int i = 0; i < k % n; i++)
    a[ids[i].second]++;
  for (auto ai : a) cout << ai << endl;
  return 0;
}
