#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  int count = 0;
  sort(begin(s), end(s));
  do {
    count++;
  } while (next_permutation(begin(s), end(s)));
  cout << count << endl;
  return 0;
}
