#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n, 0);
  vector<int> b(m, 0);
  for (auto& ai : a) cin >> ai;
  for (auto& bi : b) cin >> bi;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  int sold = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (b[j] < a[i] - k) 
      j++;
    else if (b[j] > a[i] + k) 
      i++;
    else {
      i++; j++; sold++;
    }
  }
  cout << sold << endl;

  return 0;
}
