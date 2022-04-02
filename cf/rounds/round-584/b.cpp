#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int MAX = 3000;
  int ls[100][MAX];
  int n; cin >> n;
  string line;
  cin >> line;
  for (int i = 0; i < n; i++) {
    char state = line[i];
    for (int j = 0; j < MAX; j++) {
      ls[i][j] = static_cast<int>(state - '0');
    }
  }
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < MAX; j++) cout << ls[i][j];
//   cout << endl;
// }
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    for (int k = 0; k * a < MAX; k++) {
      for (int j = b + k * a; j < min(MAX, j + a + 1); j++)
        ls[i][j] = ls[i][j] ? 0 : 1;
    }
  }
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < MAX; j++) cout << ls[i][j];
//   cout << endl;
// }
  int max = numeric_limits<int>::min();
  for (int j = 0; j < MAX; j++) {
    int on = 0;
    for (int i = 0; i < n; i++)
      if (ls[i][j]) on++;
    if (on > max) max = on;
  }
  cout << max << endl;
  return 0;
}
