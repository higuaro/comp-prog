#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int max_hap;
  inline int get(int r, int c, int n, int64_t g) {
    return (g >> (2 * (r * n  + c))) & 3;
  }

  void d(const int64_t g, const int m, const int n) {
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        int t = get(r, c, n, g);
        cout << (t == 1 ? "01" : (t == 2 ? "02": "00")) << ' ';
      }
      cout << endl;
    }
  }
  int h(int64_t g, int m, int n) {
    int total_hap = 0;
    int o[] = {-1, 0, 1, 0};

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        int t = get(r, c, n, g);
        if (!t) continue;
        int hap = t == 1 ? 120 : 40;

        for (int k = 0; k < 4; k++) {
          int rr = r + o[k];
          int cc = c + o[(k + 1) % 4];
          if (0 <= rr && rr < m && 0 <= cc && cc < n) {
            int tt = get(rr, cc, n, g);
            if (!tt) continue;
            //cout << "k = " << k << " o[k]=" << o[k] << " o[k + 1]=" << o[(k + 1) % 4] << endl;
            //cout << "(r,c)="<< r << ',' << c << " (rr, cc)=" << rr << ',' << cc
            //     << " tt " << tt << endl;
            hap += t == 1 ? -30 : 20;
          }
        }
        total_hap += hap;
      }
    }
    //cout << endl;
    //d(g, m, n);
    //cout << "total hap:" << total_hap << endl;
    return total_hap;
  }
  void solve(const int m, const int n, const int64_t g,
             int numInt, int numExt) {
    int hap = h(g, m, n);
    if (hap > max_hap) {
      d(g, m, n);
      int hh = h(g, m, n);
      cout << hh << endl;
    }
    max_hap = max(max_hap, h(g, m, n));
    if (!numInt && !numExt) return;

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        int t = get(r, c, n, g);
        if (t) continue;
        if (numInt > 0) {
          int64_t gg = g | (1 << (2 * (r * n + c)));
          solve(m, n, gg, numInt - 1, numExt);
        }
        if (numExt > 0) {
          int64_t gg = g | (2 << (2 * (r * n  + c)));
          solve(m, n, gg, numInt, numExt - 1);
        }
      }
    }
  }

  int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
    max_hap = 0;
    solve(m, n, 0LL, introvertsCount, extrovertsCount);
    return max_hap;
  }
};

int main() {
  cout << Solution().getMaxGridHappiness(3, 4, 4, 3) << endl;
  return 0;
}
