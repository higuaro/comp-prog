#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n, 0), b(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int64_t p = 0LL;
  for (int i = 0; i < n; i++) 
    p += a[i] * b[i];
  cout << (p ? "No" : "Yes") << endl;
  return 0;
}
