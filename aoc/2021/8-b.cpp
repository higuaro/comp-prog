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
bool debug = false;
int digit(const vector<bool>& d) {
  int k = count(begin(d), end(d), true);
  switch (k) {
    case 2:
      if (d[1] && d[2]) return 1;
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
      if (d[0] && d[2] && d[3] && d[4] && d[5] && d[6]) return 6;
      if (d[0] && d[1] && d[2] && d[3] && d[5] && d[6]) return 9;
      break;
    case 7:
      return 8;
  }
  return -1;
}
int to_digit(const vector<char>& conf, const string& s) {
  vector<bool> idx(7, false);
  for (int i = 0; i < s.size(); i++) {
    auto it = find(begin(conf), end(conf), s[i]);
    idx[it - begin(conf)] = true;
  }
  return digit(idx);
}
int main() {
  string line; 
  vector<int> codes;
  while (getline(cin, line)) {
    istringstream iss(line);
    bool output = false;
    string s;
    vector<string> digits;
    vector<string> code;
    while (iss >> s) {
      if (s == "|") {
        output = true;
        continue;
      }
      (output ? code : digits).push_back(s);
    }
    // 7! = 5040
    vector<char> conf{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    do {
      int k = digits.size();
      vector<int> d(k, 0);
      bool invalid = false;
      for (int i = 0; i < k; i++) {
        d[i] = to_digit(conf, digits[i]);
        if (d[i] == -1) {
          invalid = true;
          break;
        }
      }
      if (!invalid) {
        int d4 = to_digit(conf, code[0]);
        int d3 = to_digit(conf, code[1]);
        int d2 = to_digit(conf, code[2]);
        int d1 = to_digit(conf, code[3]);
        codes.push_back(d4 * 1000 + d3 * 100 + d2 * 10 + d1);
        break;
      }
    } while (next_permutation(begin(conf), end(conf)));
  }
  uint64_t s = 0;
  for (auto ci : codes) s += ci;
  cout << s << endl;
  return 0;
}
