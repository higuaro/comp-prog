#include <bits/stdc++.h>
using namespace std;
int main() {
  //int n; cin >> n;
  //vector<int64_t> c(n, 0);
  //for (int i = 0; i < n; i++) cin >> c[i];
  //sort(begin(c), end(c));

  const int M = 1e9 + 7;

  unordered_set<string> seen;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 1; k <= 5; k++) {
        ostringstream oss;
        if (i != j && i != k && j != k) {
          oss << i << ',' << j << ',' << k;
          auto seq = oss.str();
          if (!seen.count(seq)) {
            cout << seq << endl;
            seen.insert(seq);
          }
        }
      }
    }
  }
  cout << "Total " << seen.size() << endl;

  return 0;
}
