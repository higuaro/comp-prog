#include <bits/stdc++.h>
using namespace std;
inline int sum(const vector<int>& v, int i, int w) {
  return v[i + w - 1] - (i >= 1 ? v[i - 1] : 0);
}
int main() {
  int n; string s;
  cin >> n >> s;
  int l = s.size();
  int total = 0;
  vector<int> sa(n, 0), st(n, 0), sg(n, 0), sc(n, 0);
  int a, t, g, c;
  a = t = g = c = 0;
  for (int i = 0; i < l; i++) {
    switch (s[i]) {
      case 'A': a++; break;
      case 'T': t++; break;
      case 'G': g++; break;
      case 'C': c++; break;
    }
    sa[i] = a; st[i] = t; sg[i] = g; sc[i] = c;
  }
  for (int w = 2; w <= l; w++) {
    for (int i = 0; i < l - w + 1; i++) {
      a = sum(sa, i, w);
      t = sum(st, i, w);
      g = sum(sg, i, w);
      c = sum(sc, i, w);
      if (a == t && c == g) total++;
    }
  }
  cout << total << endl;
  return 0;
}
