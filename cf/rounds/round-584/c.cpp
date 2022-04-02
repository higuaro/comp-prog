#include <bits/stdc++.h>
using namespace std;
void color(int d, int col, vector<int>& v, vector<int>& colors, int& equals) {
  for (int i = 0; i < equals; i++) {
    v.push_back(d);
    colors.push_back(col);
  }
  equals = 0;
  v.push_back(d);
  colors.push_back(col);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string line; cin >> line;
    vector<int> a;
    vector<int> b;
    vector<int> colors;
    int equals = 0;
    bool invalid = false;
    for (int i = 0; i < n - 1; i++) {
      int d1 = static_cast<int>(line[i] - '0');
      int d2 = static_cast<int>(line[i + 1] - '0');
      if (d1 > d2) {
        if (b.empty()) {
          color(d1, 2, b, colors, equals);
        } else {
          if (b[b.size() - 1] <= d1) {
            color(d1, 2, b, colors, equals);
          } else {
            invalid = true;
            break;
          }
        }
      } else if (d1 < d2) {
        if (a.empty()) {
          color(d1, 1, a, colors, equals);
        } else {
          if (a[a.size() - 1] <= d1) {
            color(d1, 1, a, colors, equals);
          } else {
            invalid = true;
            break;
          }
        }
      } else {
        equals++;
      }
    }

    if (invalid) {
      cout << '-' << endl; continue;
    }

    int last_d = static_cast<int>(line[n - 1] - '0');
    int last_b = !b.empty() ? b[b.size() - 1] : -1;
    if (last_d >= last_b)
      color(last_d, 2, b, colors, equals);
    else
      color(last_d, 1, a, colors, equals);

    a.insert(a.end(), b.begin(), b.end());
    if (is_sorted(a.begin(), a.end())) {
      for (auto c : colors) cout << c;
      cout << endl;
    } else {
      cout << '-' << endl;
    }
  }
  return 0;
}
