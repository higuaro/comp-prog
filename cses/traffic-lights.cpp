#include <bits/stdc++.h>
using namespace std;
int main() {
  int x; cin >> x;
  multiset<int> ls;
  ls.insert(x);
  set<int> ps;
  ps.insert(0);
  ps.insert(x);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int pi; cin >> pi;
    auto [it, _] = ps.insert(pi);
    int prev = *std::prev(it);
    int next = *std::next(it);
    int len = next - prev;
    ls.erase(ls.find(len));
    ls.insert(pi - prev);
    ls.insert(next - pi);
    cout << *ls.rbegin() << ' ';
  }
  cout << '\n';
  return 0;
}
