#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> table(const int n, const int m) {
  vector<vector<char>> t;
  t.reserve(n);
  for (int i = 0; i < n; i++) {
    vector<char> row(m, 0);
    t.push_back(row);
  }
  return t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  auto t = table(n, m);
  for (int r = 0; r < n; r++) {
    string line; cin >> line;
    for (int c = 0; c < m; c++) {
      t[r][c] = line[c];
    }
  }

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cout << t[r][c];
    }
    cout << endl;
  }
  return 0;
}
