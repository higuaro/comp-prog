#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k; cin >> n >> k;
  vector<int> p;
  for (int i = 0; i < n; i++) {
    int pi; cin >> pi;
    p.push_back(pi);
  }
  sort(begin(p), end(p));
  int t = 0;
  for (int i = 0; i < k; i++) {
    t += p[i];
  }
  cout << t << endl;
  return 0;
}
