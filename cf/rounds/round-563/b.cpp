#include <bits/stdc++.h>
using namespace std;
inline bool is_odd(const int n) { return (n & 1) != 0; }
inline bool is_even(const int n) { return (n & 1) == 0; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n; cin >> n;
  vector<int> a;
  a.reserve(1e5);
  int num_even = 0;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    a.push_back(t);
    if (is_even(t)) num_even++;
  }
  if (num_even < n && num_even) 
    sort(begin(a), end(a));

  for (auto k : a)
    cout << k << ' ';
  cout << endl;
  return 0;
}
