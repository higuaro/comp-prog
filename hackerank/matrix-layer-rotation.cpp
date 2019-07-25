#include <bits/stdc++.h>

using namespace std;

template<int M, int N>
vector<int> ring(int (&m1)[M][N], int m, int n, int i) {
  vector<int> r;
  for (int k = i; k < n - i; k++) r.push_back(m1[i][k]);
  for (int k = i + 1; k < m - i; k++) r.push_back(m1[k][n - 1 - i]);
  for (int k = n - 2 - i; k >= i; k--) r.push_back(m1[m - 1 - i][k]);
  for (int k = m - 2 - i; k > i; k--) r.push_back(m1[k][i]);
  return r;
}
template<int M, int N>
void rotate_ring(int (&m2)[M][N], int m, int n, const vector<int>& ring, int i, int r) {
  int index = r;
  int size = static_cast<int>(ring.size());
#define I (index++ % size)
  for (int k = i; k < n - i; k++) m2[i][k] = ring[I];
  for (int k = i + 1; k < m - i; k++) m2[k][n - 1 - i] = ring[I];
  for (int k = n - 2 - i; k >= i; k--) m2[m - 1 - i][k] = ring[I];
  for (int k = m - 2 - i; k > i; k--) m2[k][i] = ring[I];
#undef I
}
int main() {
  int m, n, r; cin >> m >> n >> r;
  const int MAX = 300;
  int m1[MAX][MAX], m2[MAX][MAX];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int t; cin >> t;
      m1[i][j] = t;
    }
  }
  int num_rings = min(m, n) / 2;
  for (int rk = 0; rk < num_rings; rk++) {
    vector<int> ring_k = ring(m1, m, n, rk);
    rotate_ring(m2, m, n, ring_k, rk, r);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cout << m2[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}

