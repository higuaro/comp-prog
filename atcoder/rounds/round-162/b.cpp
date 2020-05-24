#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t s = 0LL;
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    if ((i % 3) && (i % 5)) {
      s += i;
    }
  }
  cout << s << endl;
  return 0;
}
