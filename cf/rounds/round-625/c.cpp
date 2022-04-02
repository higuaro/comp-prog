#include <bits/stdc++.h>
using namespace std;
bool has_adj(const string& line) {
  int l = line.size();
  for (int i = 1; i < l; i++) {
    char c1 = line[i - 1];
    char c2 = line[i];
    if (abs(c1 - c2) == 1) return true;
  }
  return false;
}
int solve(const string& line) {
  if (!has_adj(line) || line.size() == 1) return 0;

  int n = line.size();
  int m = 0;
  for (int i = 1; i < n; i++) {
    char c1 = line[i - 1];
    char c2 = line[i];
    if (abs(c1 - c2) == 1) {
      m = max(m, 1 + solve(string(line).erase(i - 1, 1)));
    }
  }
  return m;
}
int main() {
  int n; cin >> n;
  string line; cin >> line;
  cout << solve(line) << endl;
  return 0;
}
