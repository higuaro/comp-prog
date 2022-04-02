#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct fract {
  int64_t num;
  int64_t den;
  fract(int64_t num, int64_t den) : num(num), den(den) {
    int64_t gcd;
    do {
      gcd = __gcd(num, den);
      num /= gcd;
      den /= gcd;
    } while (gcd != 1);
  }
};
bool operator==(const fract& f1, const fract& f2) {
  return f1.num == f2.num && f1.den == f2.den;
}

struct hfrag {
  size_t operator()(const fract& f) const {
    return hash<int64_t>()(f.num) ^ (hash<int64_t>()(f.den) << 1);
  }
};

int main() {
  gp_hash_table<fract, int, hfrag> t;
  int n; cin >> n;
  vector<pair<int64_t, int64_t>> p(n, {0, 0});
  for (auto& [x, y] : p) cin >> x >> y;

  for (int i = 0; i < n; i++) {
    auto [xi, yi] = p[i];
    for (int j = i + 1; j < n; j++) {
      auto [xj, yj] = p[j];
      int64_t dx = xj - xi;
      int64_t dy = yj - yi;
      t[{dx, dy}]++;
    }
  }
  cout << t.size() * 2 << '\n';
  return 0;
}
