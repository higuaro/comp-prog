#include <bits/stdc++.h>
using namespace std;
list<int>::iterator next_r(list<int>& l, const list<int>::iterator& it) {
  auto ite = next(it);
  if (ite == l.end()) return l.begin();
  return ite;
}
int main() {
  int n; cin >> n;
  list<int> c;
  for (int i = 1; i <= n; i++)
    c.push_back(i);
  auto it = c.begin();
  while (!c.empty()) {
    it = next_r(c, it);
    cout << *it << ' ';
    auto tmp = next_r(c, it);
    c.erase(it);
    it = tmp;
  }
  cout << '\n' << endl;
  return 0;
}
