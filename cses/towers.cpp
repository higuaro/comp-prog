#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  multiset<int> towers;
  for (int i = 0; i < n; i++) {
    int ki; cin >> ki;
    auto it = towers.upper_bound(ki);
    if (it != towers.end()) 
      towers.erase(it);
    towers.insert(ki);
  }
  cout << towers.size() << '\n';
  return 0;
}
