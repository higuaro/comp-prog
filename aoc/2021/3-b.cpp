#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;
int to_int(const string& s) {
  int r = 0;
  for (int i = s.size() - 1, b = 1; i >= 0; i--, b *= 2) 
    r += static_cast<int>(s[i] - '0') * b;
  return r;
}
int main() {
  vector<string> a;
  string s;
  int k = 0;
  while (cin >> s) {
    a.push_back(s);
    k = s.size();
  }
  int n = a.size();

  unordered_set<int> discarded;
  for (int j = 0; j < k; j++) {
    int _0, _1; _0 = _1 = 0;
    for (int i = 0; i < n; i++) {
      if (discarded.count(i)) continue;
      char c = a[i][j];
      if (c == '1') _1++; else _0++;
    }
    char c = _1 >= _0 ? '1' : '0';
    for (int i = 0; i < n; i++) {
      if (discarded.count(i)) continue;
      if (a[i][j] != c) discarded.insert(i);
    }
    if (discarded.size() == n - 1) 
      break;
  }
  int aa = 0;
  for (int i = 0; i < n; i++) 
    if (!discarded.count(i)) {
      aa = to_int(a[i]);
      break;
    }

  cout << aa << endl;

  discarded.clear();
  for (int j = 0; j < k; j++) {
    int _0, _1; _0 = _1 = 0;
    for (int i = 0; i < n; i++) {
      if (discarded.count(i)) continue;
      char c = a[i][j];
      if (c == '1') _1++; else _0++;
    }
    char c = _0 <= _1 ? '0' : '1';
    for (int i = 0; i < n; i++) {
      if (discarded.count(i)) continue;
      if (a[i][j] != c) discarded.insert(i);
    }
    if (discarded.size() == n - 1) 
      break;
  }
  int bb = 0;
  for (int i = 0; i < n; i++) 
    if (!discarded.count(i)) {
      bb = to_int(a[i]);
      break;
    }
  cout << bb << endl;
  cout << aa * bb << endl;
  return 0;
}
