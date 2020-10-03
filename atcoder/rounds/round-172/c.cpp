#include <bits/stdc++.h>
using namespace std;
const uint64_t KK = 1e9;
const uint64_t NN = 1e5;
unordered_map<uint64_t, int> dp;
int solve(const vector<int>& A, const vector<int>& B, const int N, const int M,
    const int ai, const int bi, const int k) {
  if (k <= 0) return 0;
  if (ai >= N && bi >= M) return 0;
  const uint64_t P = ai * NN * KK + bi * KK + k;
  if (dp.count(P)) {
    return dp[P];
  }
  int top_a = ai < N ? A[ai] : k + 1;
  int top_b = bi < M ? B[bi] : k + 1;
  int r = max(top_a <= k ? 1 + solve(A, B, N, M, ai + 1, bi, k - top_a) : 0,
              top_b <= k ? 1 + solve(A, B, N, M, ai, bi + 1, k - top_b) : 0);
  dp[P] = r;
  return r;
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n, 0), b(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  cout << solve(a, b, n, m, 0, 0, k) << endl;

  return 0;
}
