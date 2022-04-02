#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}
int main() {
  int n; cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    a.push_back(ai);
  }
  sort(begin(a), end(a));
  int g = lcm(a[0], a[1]);
  for (int i = 1; i < n; i++) {
    g = __gcd(g, lcm(a[i - 1], a[i]));
  }
  cout << g << endl;
  return 0;
}
