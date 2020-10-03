#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int max = a[0];
  int64_t h = 0LL;
  for (int i = 1; i < n; i++) {
    int ai = a[i];
    if (ai >= max)
      max = ai;
    else 
      h += max - ai;
  }
  cout << h << endl;
  return 0;
}
