#include <bits/stdc++.h>
using namespace std;
template<typename T, size_t N, size_t M = N>
using table = array<array<T, M>, N>;

typedef int8_t i8;
table<i8, 26> g{0};
void dfs(const i8 n, array<i8, 26>& v, stack<i8>& s) {
  ;
}
int main() {

  for (size_t i = 0; i < 26; i++) {
    for (size_t j = 0; j < 26; j++) {
      g[i][j] = 0;
    }
  }
  string line;
  while (getline(cin, line, '\n')) {
    g[line[6] - '0'][line[37] - '0'] = 1;
  }
  
  return 0;

}
