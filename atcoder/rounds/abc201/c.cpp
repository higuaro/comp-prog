#include <bits/stdc++.h>
using namespace std;
int main() { 
  string s; cin >> s;
  int c = 0;
  int O = count(begin(s), end(s), 'o');
  int Q = count(begin(s), end(s), '?');
  for (int p = 0; p < 10000; p++) {
    ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << p;
    auto pin = oss.str();

    int x = 0, o = 0, q = 0;
    string S(s);
    for (int i = 0; i < 4; i++) {
      int idx = pin[i] - '0';
      switch (S[idx]) {
        case 'x': x++; break;
        case 'o': o++; S[idx] = '_'; break;
        case '?': q++; S[idx] = '_'; break;
        default: break;
      }
    }
    if (!x && o == O && q <= Q) c++;
  }
  cout << c << endl;
  return 0;
}
