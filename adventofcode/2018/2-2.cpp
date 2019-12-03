#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int similar(const string& s1, const string& s2) {
  int t = 0;
  for (size_t i = 0; i < s1.size(); i++)
    if (s1[i] == s2[i]) t++;
  return t;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  vector<string> lines;
  copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(lines));
  sort(begin(lines), end(lines));
  size_t max = numeric_limits<size_t>::min();
  size_t i_max = 0, j_max = 0;
  size_t size = lines.size();
  for (size_t i = 0; i < size; i++) { 
    string a = lines[i];
    for (size_t j = 0; j < size; j++) {
      if (i == j) continue;
      string b = lines[j];
      int s = similar(a, b);
      if (s > max) {
        max = s;
        i_max = i;
        j_max = j;
      }
    }
  }
  string a = lines[i_max];
  string b = lines[j_max];
  cout << i_max << ", " << j_max << '\n' << 
    a << '\n' << b << '\n';
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] == b[i]) cout << a[i];
  }
  cout << '\n' << std::endl;
  return 0;
}
