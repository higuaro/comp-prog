#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int64_t> fact(11, 1);
  for (int n = 1; n <= 10; n++) 
    fact[n] = n * fact[n - 1];

  int p; cin >> p;
  int c = 0;
  for (int i = fact.size() - 1; i >= 0; i--) {
    auto f = fact[i];
    while (p >= f) {
      //cout << (p / f) << "x" << f << "! " << endl;
      c += (p / f);
      p %= f;
    }
  }
  if (p) c += p;
  cout << c << endl;
  return 0;
}
