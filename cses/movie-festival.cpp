#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<int, int>> m;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    m.push_back({b, a});
  }
  sort(begin(m), end(m));
  int prev = 0;
  int movies = 0;
  for (const auto& [end, start] : m) {
    if (start >= prev) {
      prev = end;
      movies++;
    }
  }
  cout << movies << endl;
  return 0;
}
