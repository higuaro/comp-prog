#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  char cur;
  stack<char> chars;

  while (cin >> cur) {
    if (chars.empty()) {
      chars.push(cur);
      continue;
    }
    char prev = chars.top();
    if (abs(prev - cur) == 32)
      chars.pop();
    else
      chars.push(cur);
  }
  cout << chars.size() << std::endl;
  return 0;
}
