#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(3, 0);
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(begin(a), end(a));
  cout << ((a[2] - a[1]) == (a[1] - a[0]) ? "Yes" : "No") << endl;
  return 0;
}

