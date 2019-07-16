#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1, t; cin >> t;
  while (t--) {
    int b, l = 0;
    string line; cin >> line;
    l = count_if(begin(line), end(line),
        [](const char c) { return c == '.'; });
    b = static_cast<int>(line.size()) - l - 1;
    cout << "Case #" << tc++ << ": "
         << (l && b && b >= l ? 'Y' : 'N') << endl;
  }

  return 0;
}
