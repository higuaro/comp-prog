#include <bits/stdc++.h>
using namespace std;

class Solution {
  static const int oo = numeric_limits<int>::max();
  static const int N = 1e5;
  static const int K = 1e5;
  static const int M = 1e6;
  // int dp[N][K][M];
  unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> dp;
  // map<tuple<int, int, int, int>, int> dp;
  
public:
  int solve(const vector<int>& bloom, const int M, const int K,
            int i, int k, int m, int d) {
    if (i >= bloom.size()) return oo;
    // if (dp[i][k][m]) return dp[i][k][m];
    // tuple<int, int, int, int> t = {i, k, m, d};
    // if (dp.count(t)) return dp[t];
    // if (dp[i][k][m]) return dp[i][k][m];
    if (dp.count(i))
      if (dp.count(k))
        if (dp.count(m))
          if (dp.count(d)) 
            return dp[i][k][m][d];
    
    k++;
    int m2 = m;
    if (k == K) { 
      k = 0;
      m2++;
    }
    int d2 = max(d, bloom[i]);
    bool found = false;
    if (m2 == M) found = true;
    
    int ds = min(found ? d2 : solve(bloom, M, K, i + 1, k, m2, d2),
                 solve(bloom, M, K, i + 1, 0, m, d));
    // dp[i][k][m] = ds;
    // dp[t] = ds;
    dp[i][k][m][d] = ds;
    return ds;
  }
  int minDays(vector<int>& bloomDay, int m, int k) {
    //for (int _n = 0; _n < N; _n++) 
    //  for (int _k = 0; _k < K; _k++)
    //    for (int _m = 0; _m < M; _m++)
    //      dp[_n][_k][_m] = 0;
    
    int d = solve(bloomDay, m, k, 0, 0, 0, 0);
    return d == oo ? -1 : d;
  }
};
