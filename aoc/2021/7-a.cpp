#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  string line;
  vector<int> a;
  int min_ = 99999999;
  int max_ = -1;
  while (getline(cin, line)) {
    replace(begin(line), end(line), ',', ' ');
    replace(begin(line), end(line), ',', ' ');
    istringstream iss(line);
    int n;
    while (iss >> n) {
      min_ = min(min_, n);
      max_ = max(max_, n);
      a.push_back(n);
    }
  }
  uint64_t s = 999999999;
  for (int d = min_; d <= max_; d++) {
    uint64_t si = 0;
    for (auto ai : a) {
      si += abs(ai - d);
    }
    s = min(s, si);
  }
  cout << s << endl;
  return 0;
}
