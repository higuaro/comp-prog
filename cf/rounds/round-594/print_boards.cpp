#include <bits/stdc++.h>
using namespace std;
template<typename T, size_t N, size_t M>
using table = array<array<T, M>, N>;
inline bool colour(const int n, const int m, const int i, const int j, const int t) {
  return (t >> ((n - i - 1) * m + (m - j - 1))) & 1;
}
bool is_valid(const int n, const int m, const int t) {
  int offset_i[] = {0, -1, 0, 1};
  int offset_j[] = {1, 0, -1, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool c = colour(n, m, i, j, t);
      int same_colour = 0;
      for (int k = 0; k < 4; k++) {
        int ii = i + offset_i[k];
        int jj = j + offset_j[k];
        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
        bool cc = colour(n, m, ii, jj, t);
        if (c == cc) same_colour++;
        if (same_colour > 1) return false;
      }
    }
  }
  return true;
}
void print(const int n, const int m, const int t) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (colour(n, m, i, j, t) ? 'x' : '.');
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int N = 5;
  const int M = 4;
  const int K = pow(2, N * M);
  int found = 0;
  for (int k = 0; k < K; k++) {
    if (is_valid(N, M, k)) {
      found++;
      cout << "k = " << k << endl;
      print(N, M, k);
      cout << "------" << endl;
    }
  }
  cout << "Found: " << found << endl;
  return 0;
}
