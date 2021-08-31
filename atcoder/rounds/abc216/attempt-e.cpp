#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  uint64_t k; cin >> k;
  priority_queue<uint64_t> q;
  for (int i = 0; i < n; i++) {
    uint64_t ai; cin >> ai;
    q.push(ai);
  }
  uint64_t s = 0ULL;
  while (!q.empty() && k) {
    auto si = q.top(); q.pop();
    auto si_1 = q.empty() ? 0 : q.top() - 1;
    auto d = min(k, si - si_1); 
    si_1 = si - d;
    uint64_t sum_ai = si * (si + 1) / 2;
    uint64_t sum_ai_1 = si_1 * (si_1 + 1) / 2;
    s += (sum_ai - sum_ai_1);
    if (si - d) q.push(si - d);
    k -= d;
  }
  cout << s << endl;
  return 0;
}
