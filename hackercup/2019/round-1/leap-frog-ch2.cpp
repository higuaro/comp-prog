#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1, t; cin >> t;
  while (t--) {
    string line; cin >> line;
    int b, l;
    l = count_if(begin(line), end(line),
        [](const char c) { return c == '.'; });
    b = static_cast<int>(line.size()) - l - 1;
    cout << "Case #" << tc++ << ": " <<
        (l && (b >= l || b > 1) ? 'Y' : 'N') << endl;
  }
  return 0;
}
