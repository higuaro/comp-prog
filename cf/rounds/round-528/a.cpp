#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string line;
  cin >> line;
  size_t size = line.size();
  int pos = (size - 1) / 2;
  int dist = 1;
  for (int i = 0; i < size; i++) {
    cout << line[pos];
    pos += i & 1 ? -dist : dist;
    dist++;
  }
  cout << std::endl;
  return 0;
}
