#include <vector>
#include <map>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
int main() {
  string line; 
  vector<int> f;
  while (getline(cin, line)) {
    if (line == "") continue;
    replace(begin(line), end(line), ',', ' ');
    istringstream iss(line);
    int n;
    while (iss >> n) f.push_back(n);
  }
  int d = 0;
  while (d < 80) {
    int n = f.size();
    for (int i = 0; i < n; i++) {
      if (f[i] == 0) 
        f.push_back(8);
      f[i]--;
      if (f[i] < 0) f[i] = 6;
    }
    d++;
  }
  cout << f.size() << endl;

  return 0;
}
