#include <bits/stdc++.h>
using namespace std;
int main() {
  string n; cin >> n;
  for (auto d : n) {
    cout << d << endl;
    if (d == '7') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
