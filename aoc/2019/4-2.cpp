#include <bits/stdc++.h>
using namespace std;
int main() {
  int start = 234208;
  int end = 765869;
  int num_pass = 0;
  for (int n = start; n <= end; n++) {
    string s = to_string(n);
    char prev = s[0];
    bool inc = true;
    array<int, 10> adj{0};

    for (size_t i = 1; i < s.size(); i++) {
      char c = s[i];
      if (prev > c) {
        inc = false; break;
      }
      if (c == prev) adj[c - '0']++;
      prev = c;
    }
    bool group_of_2 = false;
    for (int i = 0; i <= 9; i++) {
      int a = adj[i];
      if (a == 1) group_of_2 = true;
    }
    if (inc && group_of_2) num_pass++;
  }
  cout << num_pass << endl;
}
