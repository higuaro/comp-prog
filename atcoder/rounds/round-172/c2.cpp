#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n, 0), b(m, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  vector<int> sa(n + 1, 0), sb(m + 1, 0);
  partial_sum(begin(a), end(a), begin(sa));
  partial_sum(begin(b), end(b), begin(sb));

  int ia = 0, ib = 0;
  int books = 0;
  while (k >= 0) {
    int ka = sa[ia];
    int kb = sb[ib];
    if (ka < kb) ka++; else kb++;
    int kk = min(ka, kb);
    if (k >= kk) {
      k -= ;
      books++;
    } else
      break;
  }
  cout << books << endl;
}

