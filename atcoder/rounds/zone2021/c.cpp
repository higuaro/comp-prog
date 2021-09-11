#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<pair<int, int>> as;
  for (int i = 0; i < n; i++) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    mins.push_back(
        min(min(a, b), min(c, min(d, e)))
    );
  }
  sort(begin(mins), end(mins));
  cout << mins[mins.size() - 3] << endl;
}

