#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> ns(n, 0);
  for (auto& ni : ns) cin >> ni;
  sort(begin(ns), end(ns));
  int total = 1;
  for (int i = 1; i < n; i++)
    if (ns[i] != ns[i - 1]) total++;
  cout << total << endl;
  return 0;
}
