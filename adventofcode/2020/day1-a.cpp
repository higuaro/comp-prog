#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main() {
  unordered_set<int> m;
  int n;
  while (cin >> n) 
    m.insert(n);
  for (auto v : m) {
    if (m.count(2020 - v)) {
      cout << v * (2020 - v) << endl;
      return 0;
    }
  }
  return 0;
}
