#include <bits/stdc++.h>
using namespace std;
int mod(int a, int k) {
  return ((a % k) + k) % k;
}
int main() {
  vector<int> x(4, 0);
  string l; cin >> l;
  for (int i = 0; i < 4; i++) 
    x[i] = static_cast<int>(l[i] - '0');

  if (std::equal(begin(x) + 1, end(x), begin(x))) {
    cout << "Weak" << endl;
    return 0;
  }

  for (int i = 0; i < 3; i++) {
    int xi = !x[i] ? 10 : x[i];
    int xii = !x[i + 1] ? 10 : x[i + 1];
    if (mod(xii - xi, 10) != 1) {
      cout << "Strong" << endl;
      return 0;
    }
  }

  cout << "Weak" << endl;
  return 0;
}
