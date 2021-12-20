#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> a;
  int n;
  while (cin >> n) {
    a.push_back(n);
  }
  int inc = 0;
  for (int i = 1; i < a.size(); i++) {
    if (a[i] > a[i - 1]) inc++;
  }
  cout << inc << endl;
  return 0;
}
