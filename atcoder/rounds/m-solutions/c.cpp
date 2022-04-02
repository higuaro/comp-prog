#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k; cin >> n >> k;
  vector<int64_t> a(n, 0LL);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n - k; i++)
    cout << (a[i + k] > a[i] ? "Yes" : "No") << endl;
  return 0;
}
