#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  string line;
  vector<int> buses;
  while (getline(cin, line, ',')) {
    if (line == "x") continue;
    buses.push_back(stoi(line));
  }
  int min_wait = numeric_limits<int>::max();
  int min_id = 0;
  for (auto bus_id : buses) {
    int wait = bus_id - (t % bus_id);
    if (wait < min_wait) {
      min_wait = wait;
      min_id = bus_id;
    }
  }
  cout << min_wait * min_id << endl;
  return 0;
}
