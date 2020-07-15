#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  unordered_map<string, int> tc;
  while (n--) {
    string t; cin >> t;
    if (t == "WA") tc["WA"]++;
    if (t == "AC") tc["AC"]++;
    if (t == "TLE") tc["TLE"]++;
    if (t == "RE") tc["RE"]++;
  }
  cout << "AC x " << tc["AC"] << endl;
  cout << "WA x "  << tc["WA"] << endl;
  cout << "TLE x "  << tc["TLE"] << endl;
  cout << "RE x "  << tc["RE"] << endl;
  return 0;
}
