#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  if (n & 1) {
    cout << "No" << endl;
    return 0;
  }
  string line; cin >> line;
  int index = 0;
  int l = 0, r = 0;
  stack<int> unmatched;
  for (char c : line) {
    if (c == '(') {
      l++;
      unmatched.push(index);
    } else {
      r++;
      if (!unmatched.empty())
        unmatched.pop();
    }
    index++;
  }
  if (l != r) {
    cout << "No" << endl;
    return 0;
  }
  cout << (unmatched.empty() || unmatched.size() == 1 ? "Yes" : "No") << endl;
  return 0;
}
