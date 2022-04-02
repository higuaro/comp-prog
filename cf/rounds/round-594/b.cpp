#include <bits/stdc++.h>
using namespace std;
typedef uint64_t ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> ls;
  for (int i = 0; i < n; i++) {
    int l; cin >> l;
    ls.push_back(l);
  }
  sort(begin(ls), end(ls));

  bool hor = true;
  ll x = 0LL;
  ll y = 0LL;
  int l = 0, r = n - 1;
  for (int k = 0; k < n; k++) {
    if (hor)
      x += ls[r--];
    else
      y += ls[l++];
    hor = !hor;
  }
  cout << (x * x + y * y) << endl;
  return 0;
}
