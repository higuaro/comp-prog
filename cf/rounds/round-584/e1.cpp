#include <bits/stdc++.h>
using namespace std;
int mat[4][100];
int max_rows(int n, int m) {
  int s = 0;
  for (int i = 0; i < n; i++) 
    s += *max_element(mat[i], mat[i] + m);
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int a; cin >> a;
        mat[i][j] = a;
      }
    }

    for (int j = 0; j < m; j++) {


    }
  }
  return 0;
}
