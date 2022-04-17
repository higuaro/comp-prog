#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using ordered_set = //
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = //
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;
int main() {
  int x; cin >> x;
  multiset<int> ls;
  ls.insert(x);
  ordered_set<int> ps;
  ps.insert(0);
  ps.insert(x);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int pi; cin >> pi;
    int j = ps.order_of_key(pi);
    ps.insert(pi);
    int prev = *ps.find_by_order(j - 1); 
    int next = *ps.find_by_order(j + 1); 
    int len = next - prev;
    ls.erase(ls.find(len));
    ls.insert(pi - prev);
    ls.insert(next - pi);
    cout << *ls.rbegin() << ' ';
  }
  cout << '\n';
  return 0;
}
