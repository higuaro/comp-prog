#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  set<string> st;
  cin.ignore(256, '\n');
  for (int i = 0; i < n; i++) {
    string l;
    getline(cin, l, '\n');
    if (st.count(l)) {
      cout << "Yes" << endl;
      return 0;
    }
    st.insert(l);
  }
  cout << "No" << endl;
  return 0;
}
