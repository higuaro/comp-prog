#include <bits/stdc++.h>
int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  typedef pair<int, int> pair;
  vector<pair> seq;
  seq.reserve(static_cast<size_t>(2 * 1e5));
  seq.push_back(make_pair(0, 0));
  int n; cin >> n;
  long double sum = 0.0;
  while (n--) {
    int op; cin >> op;
    switch (op) {
      case 1:
        int a; int x;
        cin >> a >> x;
        a = seq.size() >= static_cast<size_t>(a) ? a : seq.size();
        sum += static_cast<long double>(a * x);
        if (a < seq.size())
          seq[a - 1].second += x;
        else if (seq.size())
          seq[seq.size() - 1].second += x;
        break;
      case 2:
        int k; cin >> k;
        seq.push_back(make_pair(k, 0));
        sum += static_cast<long double>(k);
        break;
      case 3:
        if (seq.size() >= 2) {
          auto p = seq[seq.size() - 1];
          seq.pop_back();
          sum += static_cast<long double>(-p.first - p.second);
          if (seq.size())
            seq[seq.size() - 1].second += p.second;
        }
        break;
    }
    cout << setprecision(6) << fixed << (sum / seq.size()) << endl;
  }
  return 0;
}
