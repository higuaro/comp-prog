#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<uint64_t> output;
  uint64_t o;
  while (cin >> o)
    output.push_back(o);
  int n = output.size();
  vector<vector<uint64_t>> t(n, vector<uint64_t>(n, 0ULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      t[i][j] = output[i] + output[j];
    }
  }
  const int preamble_size = 25;

  for (int k = preamble_size; k < n; k++) {
    uint64_t v = output[k];
    bool found = false;
    for (int i = k - preamble_size; i < k; i++) {
      for (int j = k - preamble_size; j < k; j++) {
        if (t[i][j] == v) {
          found = true;
          break;
        }
      }
      if (found) break;
    }
    if (!found) {
      cout << v << endl;
      return 0;
    }
  }

  return 0;
}
