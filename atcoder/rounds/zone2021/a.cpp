#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  int t = 0;
  for (int i = 0; i <= s.size() - 4; i++) 
    if (s.substr(i, 4) == "ZONe") t++;
  cout << t << endl;
  return 0;
}
