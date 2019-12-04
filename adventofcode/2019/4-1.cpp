#include <bits/stdc++.h>
using namespace std;
int main() {
  int start = 234208;
  int end = 765869;
  int num_pass = 0;
  for (int n = start; n <= end; n++) {
    string s = to_string(n);
    char prev = s[0];
    char adj = 0;
    bool inc = true;
    for (size_t i = 1; i < s.size(); i++) {
      char c = s[i];
      if (prev > c) {
        inc = false; break;
      }
      if (prev == c) adj = c;
      prev = c;
    }
    if (inc && adj) num_pass++;
  }
  cout << num_pass << endl;
}
