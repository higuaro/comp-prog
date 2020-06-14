#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  int T = 1;
  while (t--) {
    int n; cin >> n;
    int b; cin >> b;

    vector<int> a;
    for (int i = 0; i < n; i++) {
      int v; cin >> v;
      a.push_back(v);
    }
    sort(begin(a), end(a));
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (b >= a[i]) {
        b -= a[i];
        k++;
      } else 
        break;
    }
    cout << "Case #" << T++ << ": " << k << endl;
  }
  return 0;
}
