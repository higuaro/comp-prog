#include <bits/stdc++.h>
using namespace std;
void d(const string& s, int i, int w) {
  cout << s << "(" << i << ", " << w << ")" << endl;
  int swaps = -1;
  char m = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c != 'F' && c != m) {
      m = c;
      swaps++;
    }
  }
  cout << "sol: " << max(0, swaps) << endl;
}
int main() {
  const int M = 1e9 + 7;
  int t; cin >> t;
  int T = 1;
  unordered_map<string_view, int> memo;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int swaps = -1;
    char m = 0;
    vector<int> ss(n, 0);
    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (c != 'F' && c != m) {
        m = c;
        swaps++;
      }
      ss[i] = max(swaps, 0);
    }
for (auto si : ss) cout << si << ' '; cout << endl;
    int g = 0;
    for (int w = n; w > 0; w--) {
      for (int i = 0; i < n - w + 1; i++) {
//d(s.substr(i, w), i, w);
        int f = max(0, ss[i + w - 1] - ss[i]);
//cout << "f = " << f << endl;
        g = (g + f) % M;
      }
    }
    cout << "Case #" << T++ << ": " << g << '\n';
  }
  return 0;
}
