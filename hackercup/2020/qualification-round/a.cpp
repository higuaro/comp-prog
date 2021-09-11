#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  int test = 1;
  while (t--) {
    int n; cin >> n;
    string in, out; cin >> in >> out;
    vector<string> sol(n, string(n, 'N'));
    for (int i = 0; i < n; i++) {
      sol[i][i] = 'Y';
      for (int j = i + 1; j < n; j++) {
        if (out[j - 1] == 'Y' && in[j] == 'Y')
          sol[i][j] = 'Y';
        else
          break;
      }

      for (int j = i - 1; j >= 0; j--) {
        if (out[j + 1] == 'Y' && in[j] == 'Y')
          sol[i][j] = 'Y';
        else
          break;
      }
    }

    cout << "Case #" << test++ << ":\n";
    for (int i = 0; i < n; i++)
      cout << sol[i] << endl;
  }
  return 0;
}
