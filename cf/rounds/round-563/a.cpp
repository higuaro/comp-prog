#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> a;
  int fh, sh;
  fh = sh = 0;
  int n; cin >> n;
  a.reserve(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    int t; cin >> t;
    a.push_back(t);
    if (i < n) 
      fh += t;
    else 
      sh += t;
  }
  for (int i = 0, j = 2 * n - 1; i < n; i++, j--) {
    if (a[i] != a[j]) {
      fh -= a[i]; fh += a[j];
      sh -= a[j]; sh += a[i];
      
      if (fh != sh) {
        swap(a[i], a[j]);
        break;
      } 
    }
  }
  if (fh != sh) {
    for (auto v : a)
      cout << v << ' ';
    cout << endl;
  } else 
    cout << -1 << endl;
  return 0;
}
