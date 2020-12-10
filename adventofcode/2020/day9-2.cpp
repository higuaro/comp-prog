#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t o;
  vector<uint64_t> output;
  while (cin >> o) output.push_back(o);
  int lo, hi; lo = hi = 0;
  uint64_t target = 22477624ULL;
  // uint64_t target = 127ULL;
  uint64_t t = output[lo];
  while (t != target)
    t += t < target ? output[++hi] : -output[lo++];
  auto mm = minmax_element(begin(output) + lo, begin(output) + hi);
  cout << (*mm.first + *mm.second) << endl;
  return 0;
}
