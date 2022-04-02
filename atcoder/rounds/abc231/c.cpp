#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q; cin >> n >> q;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));

  for (int i = 0; i < q; i++) {
    int qi; cin >> qi;
    auto it = lower_bound(begin(a), end(a), qi);
    cout << end(a) - it  << endl;
  }
  
  return 0;
}
