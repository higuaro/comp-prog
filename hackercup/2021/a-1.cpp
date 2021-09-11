#include <bits/stdc++.h>
using namespace std;
inline bool is_vowel(const char c) {
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
inline bool is_consonant(const char c) {
  return !is_vowel(c);
}
int main() {
  int t; cin >> t;
  int T = 1;
  while (t--) {
    string s; cin >> s;
    unordered_map<char, int> a;
    int m = numeric_limits<int>::max();
    for (int i = 0; i < 26; i++) {
      char target = 'A' + i;
      int changes = 0;
      for (char c : s) {
        if (c == target) continue;
        if (is_vowel(target)) 
          changes += is_vowel(c) ? 2 : 1;
        else 
          changes += is_consonant(c) ? 2 : 1;
      }
      m = min(m, changes);
    }
    cout << "Case #" << T++ << ": " << m << endl;
  }
  return 0;
}
