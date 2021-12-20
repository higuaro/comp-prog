#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int main() {
  string line;
  string temp; cin >> temp;
  map<string, string> rules;

  while (getline(cin, line)) {
    if (line == "") continue;
    replace(begin(line), end(line), '-', ' ');
    replace(begin(line), end(line), '>', ' ');
    istringstream iss(line);
    string s, p;
    while (iss >> s >> p) {
      rules[s] = p;
    }
  }
  temp = "NN";
  int num_steps = 2;
  cout << temp << endl;
  for (int step = 0; step < num_steps; step++) {
    string new_t = "";
    bool is_first = true;
    for (int i = 0; i < temp.size(); i++) {
      if (!is_first) new_t += ' ';
      new_t += temp[i];
      is_first = false;
    }
    for (int i = 0; i < new_t.size(); i++) {
      if (new_t[i] == ' ') {
        string r = ""; r += new_t[i - 1]; r += new_t[i + 1];
        new_t[i] = rules[r][0];
      }
    }
    temp = new_t;
    cout << temp << endl;
  }
  unordered_map<char, uint64_t> count;
  for (auto c : temp) {
    count[c]++;
  }
  uint64_t min_ = 99999999, max_ = 0;
  for (auto [c, v] : count) {
    min_ = min(min_, v);
    max_ = max(max_, v);
  }
  cout << max_ << ',' << min_ << endl;
  cout << max_ - min_ << endl;
  return 0;
}
