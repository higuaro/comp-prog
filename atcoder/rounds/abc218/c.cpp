#include <bits/stdc++.h>
using namespace std;
bool eq(const vector<pair<int, int>>& s, vector<pair<int, int>>& t) {
  if (s.size() != t.size()) return false;
  set<pair<int, int>> ss(begin(s), end(s));
  for (auto p : t) 
    if (!ss.count(p)) return false;
  return true;
}
void translate_to_0(vector<pair<int, int>>& s) {
  pair<int, int> min_s{999, 999};
  for (auto [i, j] : s) {
    min_s.first =  min(min_s.first, i);
    min_s.second = min(min_s.second, j);
  }
  for (auto& p : s) {
    p.first  -= min_s.first;
    p.second -= min_s.second;
  }
}
void rot(const int n, vector<pair<int, int>>& t) {
  for (auto& p : t) {
    int i = p.first;
    int j = p.second;
    p.first = n - j - 1;
    p.second = i;
  }
}
int main() {
  int n; cin >> n;
  vector<pair<int, int>> s, t;
  for (int i = 0; i < n; i++) {
    string l; cin >> l;
    for (int j = 0; j < n; j++)
      if (l[j] == '#') s.emplace_back(i, j);
  }
  for (int i = 0; i < n; i++) {
    string l; cin >> l;
    for (int j = 0; j < n; j++)
      if (l[j] == '#') t.emplace_back(i, j);
  }
  translate_to_0(s);
  for (int k = 0; k < 5; k++) {
    rot(n, t);
    translate_to_0(t);
    if (eq(s, t)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
