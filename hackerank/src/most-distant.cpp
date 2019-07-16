#include <bits/stdc++.h>

using namespace std;
typedef int64_t ll;
typedef pair<ll, ll> p;

inline long double sqr(ll n) { return static_cast<long double>(n * n); }
inline long double dist(const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
  return sqrt(sqr(p2.first - p1.first) + sqr(p2.second - p1.second));
}
// Complete the solve function below.
long double solve(const vector<p>& coordinates) {
  ll minX, maxX, minY, maxY;
  minX = minY = numeric_limits<ll>::max();
  maxX = maxY = numeric_limits<ll>::min();

  for (auto p : coordinates) {
    auto x = p.first;
    auto y = p.second;
    minX = min(minX, x);
    maxX = max(maxX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);
  }

  p p1 = make_pair(minX, 0);
  p p2 = make_pair(0, minY);
  p p3 = make_pair(maxX, 0);
  p p4 = make_pair(0, maxY);
  long double d1 = dist(p1, p2);
  long double d2 = dist(p1, p3);
  long double d3 = dist(p1, p4);
  long double d4 = dist(p2, p3);
  long double d5 = dist(p2, p4);
  long double d6 = dist(p3, p4);
  return max(max(d1, max(d2, d3)), max(d4, max(d5, d6)));
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  int n; cin >> n;
  vector<p> coordinates;
  coordinates.reserve(n);
  for (int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y;
    coordinates.push_back(make_pair(x, y));
  }
  long double result = solve(coordinates);
  fout << fixed << setprecision(12) << result << endl;
  return 0;
}
