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
  uint64_t score = 0;
  vector<char> cc{')', ']', '}', '>'};
  vector<int> s{3, 57, 1197, 25137};
  stack<char> open, closed;
  while (getline(cin, line)) {
    for (int i = 0; i < line.size(); i++) {
      char c = line[i];
      if (is_open(c)) open.push(c);
      else {
        char cc = open.top();
        if (index(cc) == index(c)) {
          open.pop();
        } else {
          score += s[index(c)];
          break;
        }
      }
    }
  }
  cout << score << endl;
  return 0;
}
