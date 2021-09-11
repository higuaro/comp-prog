#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_set<string> s{"ABC", "ARC", "AGC", "AHC"};
  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  for (auto ss : s) {
    if (ss == s1 || ss == s2 || ss == s3) continue;
    cout << ss << endl;
    return 0;
  }
  return 0;
}
