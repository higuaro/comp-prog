#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  int h = (n / 500) * 1000;
  n %= 500;
  h += (n / 5) * 5;
  cout << h << endl;
}
