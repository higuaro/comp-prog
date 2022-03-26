#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  set<string> ss;
  sort(begin(s), end(s));
  do {
    ss.insert(s);
  } while (next_permutation(begin(s), end(s)));
  cout << ss.size() << endl;
  for (auto si : ss)
    cout << si << endl;
  return 0;
}
