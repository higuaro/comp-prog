#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
int digit(const vector<bool>& d) {
  int k = count_if(begin(d), end(d), true);
  switch (k) {
    case 2:
      if (d[0] && d[1]) return 1;
      break;
    case 3:
      if (d[0] && d[1] && d[2]) return 7;
      break;
    case 4:
      if (d[1] && d[2] && d[5] && d[6]) return 4;
      break;
    case 5: 
      if (d[0] && d[1] && d[6] && d[4] && d[3]) return 2;
      if (d[0] && d[1] && d[2] && d[3] && d[6]) return 3;
      if (d[0] && d[5] && d[6] && d[2] && d[3]) return 5;
      break;
    case 6:
      if (d[0] && d[1] && d[2] && d[3] && d[4] && d[5]) return 0;
      if (d[0] && d[1] && d[2] && d[3] && d[4] && d[6]) return 6;
      if (d[0] && d[1] && d[2] && d[3] && d[5] && d[6]) return 9;
      break;
    case 7:
      return 8;
  }
  return -1;
}
int to_digit(const vector<int>& conf, const string& s) {
  vector<bool> idx(s.size(), false);
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    auto it = find(begin(conf), end(conf), c);
    idx[it - begin(conf)] = true;
  }
  return digit(idx);
}
int main() {
  int d = 0;
  string line; 
  while (getline(cin, line)) {
    istringstream iss(line);
    bool output = false;
    string s;
    while (iss >> s) {
      if (s == "|") output = true;
      if (!output) continue;
      int k = s.size();
      switch (k) {
        case 2:
        case 3:
        case 4:
        case 7:
          d++;
          break;
      }
    }
  }
  //vector<int> a;
  //while (getline(cin, line)) {
  //  replace(begin(line), end(line), ',', ' ');
  //  istringstream iss(line);
  //  int n;
  //  while (iss >> n) {
  //    a.push_back(n);
  //  }
  //}

  //cout << "" << endl;
  cout << d << endl;
  return 0;
}
