#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_map<char, int> m;
  string s; cin >> s;
  for (char c : s) m[c]++;
  int n = s.size();
  bool odd_n = n & 1;
  int odd_counts = 0;
  for (auto [_, count] : m) 
    odd_counts += (count & 1);
  if (odd_counts > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  if (odd_counts == 1 && !odd_n) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  string odd_string = "";
  string half_pal = "";
  for (auto [c, count] : m) {
    if (!(count & 1)) {
      for (int k = 0; k < count / 2; k++)
        half_pal += c;
    } else {
      for (int k = 0; k < count; k++)
       odd_string += c;
    }
  }

  string other_half = half_pal;
  reverse(begin(other_half), end(other_half));
  if (odd_string != "") {
    cout << half_pal << odd_string << other_half << endl;
  } else {
    cout << half_pal << other_half << endl;
  }
  return 0;
}
