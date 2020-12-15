#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> start;
  string token;
  while (getline(cin, token, ','))
    start.push_back(stoi(token));

  int turn = 1;
  int last, spoke;
  unordered_map<int, pair<int, int>> spoken;
  for (int i = 0; i < start.size(); i++, turn++) {
    spoke = start[i];
    spoken[spoke] = {-1, turn};
    last = spoke;
  }
  while (turn <= 30000000) {
    auto [first, second] = spoken[last];
    spoke = first == -1 ? 0 : second - first;
    if (spoken.count(spoke)) {
      auto n = spoken[spoke];
      spoken[spoke] = {n.second, turn};
    } else {
      spoken[spoke] = {-1, turn};
    }
    last = spoke;
    turn++;
  }
  cout << last << endl;
  return 0;
}
