#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
  vector<int> a;
  int n;
  while (cin >> n) 
    a.push_back(n);
  int count = 0;
  for (int i = 1; i < a.size() - 2; i++)
    if (a[i + 2] > a[i - 1]) count++;
  cout << count << endl;
  return 0;
}
