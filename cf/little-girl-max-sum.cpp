#include <bits/stdc++.h>
int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  typedef pair<int, int> pair;

  int n, q; cin >> n >> q;
  vector<int> a(n, 0);
  vector<pair> queries(q, make_pair(0, 0));
  vector<pair> hot_zone(n, make_pair(0, 0));
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    a[i] = t;
    hot_zone[i].first = i;
  }

  vector<pair> events(n, make_pair(0, 0));
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    queries[i] = make_pair(l - 1, r - 1);
    events[l - 1].first++;  // open event
    events[r - 1].second++; // close event
  }

  int heat = 0;
  for (int i = 0; i < n; i++) {
    auto e = events[i];
    heat += e.first;
    hot_zone[i].second = heat;
    heat -= e.second;
  }

  sort(begin(a), end(a));
  sort(begin(hot_zone), end(hot_zone), [](const pair& p1, const pair& p2) {
    return p1.second < p2.second;
  });

  vector<int> b(n, 0);
  for (int i = 0; i < n; i++)
    b[hot_zone[i].first] = a[i];

  uint64_t sum = 0LL;
  vector<uint64_t> sum_b(n, 0LL);
  for (int i = 0; i < n; i++) {
    sum += b[i];
    sum_b[i] = sum;
  }

  sum = 0LL;
  for (auto q : queries)
    sum += sum_b[q.second] - (q.first - 1 < 0 ? 0LL : sum_b[q.first - 1]);
  cout << sum << endl;
  return 0;
}
