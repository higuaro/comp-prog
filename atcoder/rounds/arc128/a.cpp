#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long double ld;
ld solve(const vector<int>& a, const int n, int i = 0) {
  if (i >= n) 
    return 0;

}
int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for (auto& ai : a) cin >> ai;
  cout << solve(a, n) << endl;
  return 0;
}
