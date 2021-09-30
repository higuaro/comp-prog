#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n; int ti; cin >> ti;
  vector<int> a(2 * n, 0);
  iota(begin(a), end(a), 1);
  int c = 0;
  do {
    int t = 0;
    for (int i = 0; i < 2 * n - 1; i++)
      if (a[i] < a[i + 1]) t++;
    if (t == ti) {
      //for (auto ai : a) cout << ai << ' ';
      //cout << endl;
      c++;
    }
  } while (next_permutation(begin(a), end(a)));
  cout << c << endl;
  return 0;
}
