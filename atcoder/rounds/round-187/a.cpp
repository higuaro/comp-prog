#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b; cin >> a >> b;
  int sa = 0;
  for (auto c : a) 
    sa += (c - '0');
  int sb = 0;
  for (auto c : b) 
    sb += (c - '0');

  cout << max(sa, sb) << endl;
  return 0;
}
