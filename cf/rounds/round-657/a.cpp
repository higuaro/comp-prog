#include <bits/stdc++.h>
using namespace std;
const string S = "abacaba";
int count(const string& s, const int n) {
  const int L = S.size();
  int o = 0;
  for (int i = 0; i < n; i++) {
    bool found = true;
    for (int j = 0; j < L; j++) {
      if (s[i + j] != S[j]) {
        found = false;
        break;
      }
    }
    if (found) o++;
  }
  return o;
}
vector<int> matches(const string& s, const int n) {
  const int L = S.size();
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    bool found = true;
    for (int j = 0; j < L; j++) {
      if (i + j >= n) {
        found = false;
        break;
      }
      char c = s[i + j];
      if (c != '?' && c != S[j]) {
        found = false;
        break;
      }
    }
    if (found) {
      pos.push_back(i);
    }
  }
  return pos;
}
string replace_q(string& s, const int n) {
  for (int i = 0; i < n; i++)
    if (s[i] == '?') s[i] = 'z';
  return s;
}

int main() {
  const int L = S.size();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;

    int o = count(s, n);
    if (o == 1) {
      cout << "Yes" << endl;
      cout << replace_q(s, n) << endl;
      continue;
    } if (o > 1) {
      cout << "No" << endl;
      continue;
    }

    auto pos = matches(s, n);
    if (pos.empty()) {
      cout << "No" << endl;
      continue;
    }
    bool found = false;
    for (auto p : pos) {
      string ss = s;
      for (int i = 0; i < L; i++)
        ss[p + i] = S[i];
      ss = replace_q(ss, n);

      int o = count(ss, n);
      if (o == 1) {
        cout << "Yes\n" << ss << endl;
        found = true;
        break;
      }
    }
    if (!found) cout << "No" << endl;
  }
  return 0;
}
