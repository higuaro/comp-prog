#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
int main(int argc, char** argv) {
  int n; cin >> n;
  vector<pair<int, int>> ab(n, {0, 0});
  for (auto& abi : ab)
    cin >> abi.first >> abi.second;
  vector<pair<int, bool>> events;
  for (auto [a, b] : ab) {
    events.emplace_back(a, false);
    events.emplace_back(a + b - 1, true);
  }

  sort(begin(events), end(events));
  //gp_hash_table<int, int> ks;
  unordered_map<int, int> ks;
  int k = 0;
  int a_prev = events[0].first;
  queue<bool> q;
  for (auto [a, logged_off] : events) {
    int d = a - a_prev;
    if (d) {
      while (!q.empty()) {
        bool off = q.front(); q.pop();
        k += off ? -1 : 1;
      }
      ks[k] += d;
    }
    q.push(logged_off);
    a_prev = a;
  }

  for (int ki = 1; ki <= n; ki++) 
    cout << ks[ki] << ' ';
  cout << endl;
  return 0;
}
