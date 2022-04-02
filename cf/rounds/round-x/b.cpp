#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int numbers[6] = {4, 8, 15, 16, 23, 42};
  int a[7][7];
  for (int i = 1; i < 7; i++)
    a[i][0] = a[0][i] = numbers[i - 1];

  for (int i = 1; i < 7; i++)
    for (int j = 1; j < 7; j++)
      a[i][j] = a[i][0] * a[0][j];

  array<int, 7> pos{0};
  int q = 4;
  int p = 1;
  while (q--) {
    cout << "? " << p << ' ' << p + 1 << endl;
    int prod;
    if (!(cin >> prod)) return 0;

    int n1, n2; n1 = n2 = 0;
    for (int i = 1; i < 7; i++) 
      for (int j = 1; j < 7; j++)
        if (i != j && a[i][j] == prod) {
          n1 = a[i][0];
          n2 = a[0][j];
          break;
        }
    if (p > 1) {
      int pn1 = pos[p - 2];
      if (n1 == pn1 || n2 == pn1)
        swap(pos[p - 2], pos[p - 1]);
      int pn2 = pos[p - 1];
      pos[p] = n1 == pn2 ? n2 : n1;
    } else {
      pos[p - 1] = n1;
      pos[p] = n2;
    }
    p++;
  }

  set<int> found;
  cout << '!';
  for (int i = 0; i < 5; i++) {
    cout << ' ' << pos[i];
    found.insert(pos[i]);
  }
  for (int i = 0; i < 6; i++) {
    if (!found.count(numbers[i])) {
      cout << ' ' << numbers[i] << endl;
      return 0;
    }
  }
  return 0;
}
