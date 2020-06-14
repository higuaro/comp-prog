#include <bits/stdc++.h>
using namespace std;

class Solution {
  static const int M = 100;
  static const int oo = numeric_limits<int>::max();
  int cheapest = oo;

public:
  int neighborhoods(const vector<int>& houses) {
    int p = houses[0];
    int n = 0;
    for (int i = 1; i < static_cast<int>(houses.size()); i++) {
      int h = houses[i];
      if (h != p) {
        if (p) n++;
        p = h;
      }
    }
    return n + (p ? 1 : 0);
  }

  void solve(const vector<vector<int>>& costs,
             vector<int>& houses,
             int painted,
             int m, int n, int house, int cost, int target) {
    if (houses[house] || cost >= cheapest) return;

    for (int colour = 0; colour < n; colour++) {
      int c = cost + costs[house][colour];
      if (c >= cheapest) continue;

      houses[house] = colour + 1;
      painted++;

      int neighbors = neighborhoods(houses);
// for (int i = 0; i < m; i++) cout << houses[i] << ' '; cout << ':' << neighbors << endl;
      if (neighbors == target && painted == m) {
// cout << "sol " << c << endl;
        cheapest = min(cheapest, c);
        houses[house] = 0;
        continue;
      }

      if (neighbors <= target + 1)
        for (int h = house + 1; h < m; h++)
          solve(costs, houses, painted, m, n, h, c, target);

      houses[house] = 0;
      painted--;
    }
  }

  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    size_t painted = 0;
    int first = oo;
    for (int house = 0; house < m; house++)
      if (houses[house]) {
        painted++;
      } else
        first = min(first, house);

    if (painted == houses.size())
      return neighborhoods(houses) != target ? -1 : 0;

    solve(cost, houses, painted, m, n, first, 0, target);

    return cheapest == oo ? -1 : cheapest;
  }
};

int main() {
  ifstream fis("./paint-house-iii.in");
  int expected_sol;
  auto l = [=] (const char c) -> bool {
    return c == '[' || c == ']';
  };
  while (fis >> expected_sol) {
    cerr << expected_sol << endl;
    vector<int> houses;
    string line;
    fis.ignore(256, '\n');
    getline(fis, line, '\n');

    line.erase(remove_if(begin(line), end(line), l), end(line));
    replace(begin(line), end(line), ',', ' ');
    istringstream iss(line);
    int h;
    while (iss >> h)
      houses.push_back(h);
    getline(fis, line, '\n');
    int m, n, t;
    fis >> m >> n >> t;

    line.erase(remove_if(begin(line), end(line), l), end(line));
    replace(begin(line), end(line), ',', ' ');
    istringstream iss2(line);
    vector<vector<int>> cost;
    for (int i = 0; i < m; i++) {
      vector<int> row;
      for (int j = 0; j < n; j++) {
        int c;
        iss2 >> c;
        row.push_back(c);
      }
      cost.push_back(row);
    }
    fis.ignore(256, '\n');
    getline(fis, line, '\n');

    Solution sol;
    int s = sol.minCost(houses, cost, m, n, t);
    cout << "Solution: " << s << endl;
    cout << "Expected: " << expected_sol << endl;
    cout << "----------------------------" << endl;
  }

  return 0;
}
