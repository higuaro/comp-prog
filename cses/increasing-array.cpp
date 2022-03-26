#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n; cin >> n;
  int64_t m = 0;
  int64_t total = 0;
  for (int i = 0; i < n; i++) { 
    int64_t ai; cin >> ai;
    m = max(m, ai);
    total += (m - ai);
  }
  cout << total << endl;
  return 0;
}
