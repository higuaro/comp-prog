#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int64_t n; cin >> n;
    int m; cin >> m;
    vector<pair<int, int>> flowers;
    for (int i = 0; i < m; i++) {
      int ai, bi; cin >> ai >> bi;
      flowers.emplace_back(ai, bi);
    }
    sort(begin(flowers), end(flowers),
      [=](const pair<int, int>& f1, const pair<int, int>& f2) {
        int64_t h1 = f1.first + (n - 1) * f1.second;
        int64_t h2 = f2.first + (n - 1) * f2.second;
        return h1 < h2;
    });
    auto [ma, mb]  = flowers.back();
// cout << "ma " << ma << ',' << mb << endl;
    int64_t r = 0LL;
    if (n == 1) {
      int max_a = 0;
      for (auto& f : flowers)
        max_a = max(max_a, f.first);
      r += max_a;
    } else if ((n % 2) != 0) {
      r = ma + max(0LL, n - 2LL) * mb;
      int max_a = 0;
      for (auto& f : flowers)
        max_a = max(max_a, f.first);
      r += max_a;
    } else {
      r = ma + max(0LL, n - 1LL) * mb;
    }
    cout << r << endl;

    cin.ignore(256, '\n');
  }
}
