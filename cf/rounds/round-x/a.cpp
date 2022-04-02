#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  while (n--) {
    int l; cin >> l;
    string s; cin >> s;
    size_t pos8 = s.find("8");
    cout << (pos8 == string::npos
        ? "NO"
        : (((s.size() - pos8) >= 11 ? "YES" : "NO")))
      << '\n';
  }
  return 0;
}
