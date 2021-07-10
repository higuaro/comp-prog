#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n, 0), b(n, 0), c(n, 0);
  for (auto& ai : a) cin >> ai;
  for (auto& bi : b) cin >> bi;
  for (auto& ci : c) cin >> ci;

  unordered_map<int, int> count;
  vector<int> bb;
  for (auto ci : c) {
    int bbi = b[ci - 1];
    bb.push_back(bbi);
    count[bbi]++;
  }
  uint64_t t = 0;
  for (auto ai : a) t += static_cast<uint64_t>(count[ai]);
  cout << t << endl;
  return 0;
}
