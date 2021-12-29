#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int vi;
  while (cin >> vi) 
    v.push_back(vi);
  int n = v.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int  k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (v[i] + v[j] + v[k] == 2020) {
          cout << v[i] * v[j] * v[k] << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
