#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string line;
  int num2s = 0, num3s = 0;
  while (cin >> line) {
    array<char, 26> alph{0};
    bool found2, found3;
    found2 = found3 = false;
    for (auto c : line) {
      alph[c - 'a']++;
    }
    for (size_t i = 0; i < 26; i++) {
      if (alph[i] == 3) found3 = true;
      if (alph[i] == 2) found2 = true;
      if (found2 && found3) break;
    }
    if (found2) num2s++;
    if (found3) num3s++;
  }
  cout << num2s * num3s << std::endl;
  return 0;
}
