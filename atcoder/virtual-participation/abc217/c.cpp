#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> p(n, 0); 
  for (int i = 0; i < n; i++) cin >> p[i];
  vector<int> q(n, 0);
  for (int i = 0; i < n; i++) 
    q[p[i] - 1] = i + 1;
  for (auto qi : q) 
    cout << qi << ' ';
  cout << endl;
  return 0;
}
