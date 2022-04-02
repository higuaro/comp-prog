#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 0; i < 26; i++) {
    int n; cin >> n;
    cout << static_cast<char>('a' + n - 1);
  }
  cout << endl;
  return 0;
}
