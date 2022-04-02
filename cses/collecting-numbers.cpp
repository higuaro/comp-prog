#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  unordered_set<int> x;
  int runs = 1;
  for (int i = 0; i < n; i++) {
    int xi; cin >> xi;
    if (xi > 1 && !x.count(xi - 1)) runs++;
    x.insert(xi);
  }
  cout << runs << '\n';
  return 0;
}
