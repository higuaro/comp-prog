#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
pair<int, int> count(const string& seq) {
  int l, r; l = r = 0;
  for (auto c : seq) {
    if (c == '(') l++;
    if (c == ')') {
      if (l) l--;
      else r++;
    }
  }
  return make_pair(l, r);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  vector<pair<int, int>> seqs;
  string seq;
  while (cin >> seq) {
    seqs.push_back(count(seq));
  }
  map<pair<int, int>, int> pairs;
  for (auto lr : seqs) pairs[lr]++;

  int matches = 0;
  for (auto lr : seqs) {
    auto [l, r] = lr;
    auto match = make_pair(r, l);
    if (l && r) continue;
    int offset = l == r ? 2 : 1;

    if (pairs[lr] - offset >= 0 && pairs[match] - offset >= 0) {
      matches++;
      pairs[lr]--;
      pairs[match]--;
    }
  }

  cout << matches << std::endl;
  return 0;
}
