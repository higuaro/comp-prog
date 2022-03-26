#include <bits/stdc++.h>
using namespace std;

void solve(int n, char s, char d, char t) {
  const char to = ' ';
  if (n == 1) {
    cout << s << to << d << "\n";
    return;
  }
  
  if (n == 2) {
    cout << s << to << t << "\n";
    cout << s << to << d << "\n";
    cout << t << to << d << "\n";
    return;
  }
    
  solve(n - 1, s, t, d);
  cout << s << to << d << "\n";
  solve(n - 1, t, d, s);
}
int main() {
  int n; cin >> n;
  int p = pow(2, n) - 1;
  cout << p << endl;
  solve(n, '1', '3', '2');
  return 0;
}
