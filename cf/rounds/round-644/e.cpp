#include <bits/stdc++.h>
using namespace std;
template<int N>
using table = array<array<int, N>, N>;
int main() {
  int t; cin >> t;
  const int N = 50;
  table<N> a;
  while (t--) {
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++)
        a[i][j] = 0;
    
    int n; cin >> n;
    int bullets = 0;
    for (int i = 0; i < n; i++) {
      string line; cin >> line;
      for (int j = 0; j < n; j++) {
        a[i][j] = static_cast<int>(line[j] - '0');
        if (a[i][j]) bullets;
      }
    }
    if (bullets == n * n) {
      cout << "YES" << endl;
      continue;
    }

    unordered_map<int, bool> walls;
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= 0; j--) {
        if (a[i][j]) {
          walls[i * n + j] = true;
        } else
          break;
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = n - 1; i >= 0; i--) {
        if (a[i][j]) {
          walls[i * n + j] = true;
        } else
          break;
      }
    }


    bool valid = true;
    for (int i = 0; i < n; i++) {
      for (int j = n - 2; j >= 0; j--) {
        if (a[i][j] && !walls[i * n + j]) {
          walls[i * n + j] = true;
        } else
          break;
      }
      if (!valid) break;
    }
    if (!valid) {
      cout << "NO" << endl;
      continue;
    }

    for (int j = 0; j < n; j++) {
      for (int i = n - 1; i >= 0; i--) {
        if (a[i][j]) {
          walls[i * n + j] = true;
        } else
          break;
      }
      if (!valid) break;
    }

    cout << (valid ? "YES" : "NO") << endl;
  }
  return 0;
}
