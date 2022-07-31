#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<tuple<int, bool, int>> allocations;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    allocations.emplace_back(a, false, i);
    allocations.emplace_back(b, true, i);
  }
  int allocated = 0;
  vector<pair<int, int>> queries;
  unordered_map<int, int> rooms;
  priority_queue<int> available;
  sort(begin(allocations), end(allocations));
  for (auto [day, is_leaving, customer] : allocations) {
    if (is_leaving) {
      available.push(-rooms[customer]);
      rooms.erase(customer);
    } else {
      if (available.empty()) {
        allocated++;
        rooms[customer] = allocated;
      } else {
        rooms[customer] = -available.top();
        available.pop();
      }
      queries.emplace_back(customer, rooms[customer]);
    }
  }
  sort(begin(queries), end(queries));
  cout << allocated << '\n';
  for (auto [customer, room] : queries) cout << room << ' ';
  cout << endl;
  return 0;
}