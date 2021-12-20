#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;
bool is_open(char c) {
  return c == '(' || c == '[' || c == '{' || c == '<';
}
int index(char c) {
  switch (c) {
    case '(':
    case ')':
      return 0;
    case '[':
    case ']':
      return 1;
    case '{':
    case '}':
      return 2;
    default:
      return 3;
  }
}
int main() {
  string line;
  vector<string> lines;
  vector<uint64_t> scores;
  while (getline(cin, line)) {
    bool corrupted = false;
    stack<char> open;
    for (int i = 0; i < line.size(); i++) {
      char c = line[i];
      if (is_open(c)) open.push(c);
      else {
        char cc = open.top();
        if (index(cc) == index(c)) {
          open.pop();
        } else {
          corrupted = true;
          break;
        }
      }
    }
    if (corrupted) continue;
    uint64_t ss = 0;
    while (!open.empty()) {
      char c = open.top(); open.pop();
      ss = ss * 5 + index(c) + 1;
    }
    if (ss) scores.push_back(ss);
  }
  sort(begin(scores), end(scores));
  cout << "scores:" << endl;
  for (auto s : scores) cout << s << endl;
  cout << scores[scores.size() / 2] << endl;
  return 0;
}
