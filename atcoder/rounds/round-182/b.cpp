#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  int m = *max_element(begin(a), end(a));
  int max_k = 0;
  int max_kc = 0;
  for (int k = 2; k <= m; k++) {
    int kc = 0;
    for (auto ai : a) 
      if (!(ai % k)) kc++;
    if (kc > max_kc) {
      max_kc = kc;
      max_k = k;
    }
  }
  cout << max_k << endl;
  return 0;
}
