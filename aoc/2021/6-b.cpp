#include <vector>
#include <map>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
using namespace std;
int main() {
  string line; 
  unordered_map<int, uint64_t> m;
  while (getline(cin, line)) {
    if (line == "") continue;
    replace(begin(line), end(line), ',', ' ');
    istringstream iss(line);
    int n;
    while (iss >> n) m[n]++;
  }
  int d = 0;
  while (d < 256) {
    uint64_t t = m[0];
    for (int i = 1; i <= 8; i++) m[i - 1] = m[i];
    m[6] += t;
    m[8] = t;
    d++;
  }
  uint64_t total = 0;
  for (int i = 0; i <= 8; i++) 
    total += m[i];
  cout << total << endl;

  return 0;
}
