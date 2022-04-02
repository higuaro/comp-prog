#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  int n = s.size();
  if (n == 1) {
    cout << s << endl;
    return 0;
  }
  sort(begin(s), end(s));
  int64_t best = 0;
  do {
    for (int k = 1; k < n; k++) {
      string sa = s.substr(0, k);
      string sb = s.substr(k, n - k);
      if (sa[0] == '0' || sb[0] == '0') continue;
      int64_t a = stoi(sa);
      int64_t b = stoi(sb);
      best = max(best, a * b);
    }
  } while (next_permutation(begin(s), end(s)));
  cout << best << endl;
  return 0;
}
