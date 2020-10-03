#include <bits/stdc++.h>
using namespace std;
int main() {
  string n; cin >> n;
  uint64_t s = 0ULL;
  for (char d : n) 
    s += static_cast<int>(d - '0');
  cout << (s % 9ULL ? "No" : "Yes") << endl;
  return 0;
}
