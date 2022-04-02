#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
  int t; cin >> t;
  while (t--) {
    int n, k, w;
    cin >> n >> k >> w;
    vector<int64_t> ls(n, 0);
    vector<int64_t> hs(n, 0);

    for (int i = 0; i < k; i++)
      cin >> ls[i];
    int64_t al, bl, cl, dl;
    cin >> al >> bl >> cl >> dl;

    for (int i = 0; i < k; i++)
      cin >> hs[i];
    int64_t ah, bh, ch, dh;
    cin >> ah >> bh >> ch >> dh;

    for (int i = k; i < n; i++) {
      ls[i] = (al * ls[i - 2] + bl * ls[i - 1] + cl) % dl;
      hs[i] = (ah * hs[i - 2] + bh * hs[i - 1] + ch) % dh;
    }

    vector<tuple<int, int, bool>> events;
    for (int i = 0; i < n; i++) {
      int64_t l = ls[i];
      events.emplace_back(l, i, true);
      events.emplace_back(l + w, i, false);
    }
    sort(begin(events), end(events), [=](const auto& e1, const auto& e2) {
      return get<0>(e1) < get<0>(e2);
    });

    for (auto [x, li, type] : events) {
      cout << (type ? "open" : "close") << ' ' << li << " at " << x << endl;
    }
  }
  return 0;
}
