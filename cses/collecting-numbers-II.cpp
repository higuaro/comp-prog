#include <bits/stdc++.h>
using namespace std;
int runs(const vector<int>& x) {
  unordered_map<int, int> pos;
  for (int i = 0; i < x.size(); i++) pos[x[i]] = i;
  int r = 0;
  for (auto xi : x) 
    if (pos.count(xi - 1))
      r += pos[xi - 1] > pos[xi] ? 1 : 0;
  return r;
}

int change(vector<int>& pos, vector<int>& x, int a, int b) {
  int xa = x[a], xb = x[b];
  set<int> nums{xa - 1, xa, xa + 1, xb - 1, xb, xb + 1};
  nums.erase(0);
  nums.erase(x.size() + 1);

  vector<int> xs(begin(nums), end(nums));
  auto cmp = [&pos](const int n1, const int n2) { return pos[n1] < pos[n2]; };
  sort(begin(xs), end(xs), cmp);
// cout << "before xs: "; for (auto xi : xs) cout << xi << ','; cout << '\n';
  int r1 = runs(xs);

  swap(x[a], x[b]);
  pos[xa] = b; pos[xb] = a;

  sort(begin(xs), end(xs), cmp);
// cout << " after xs: "; for (auto xi : xs) cout << xi << ','; cout << '\n';
  int r2 = runs(xs);
// cout << "delta: " << r2 - r1 << '\n';
  return r2 - r1;
}

int main() {
  int n, m; cin >> n >> m;
  vector<int> pos(n, 0);
  vector<int> x(n, 0);
  for (int i = 0; i < n; i++) {
    int xi; cin >> xi;
    x[i] = xi;
    pos[xi] = i;
  }
  int runs = 1;
  for (int k = 2; k <= n; k++) 
    if (pos[k - 1] > pos[k]) runs++;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    runs += change(pos, x, a, b);
    cout << runs << '\n';
  }
  return 0;
}
