#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  int best = 0;
  char prev = 0;
  int count = 0;
  for (char c : s) 
    if (c == prev)
      best = max(++count, best);
    else {
      prev = c;
      count = 1;
    }
  cout << max(count, best) << endl;
  return 0;
}
