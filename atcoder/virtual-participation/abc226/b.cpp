#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int main() {
  int n; cin >> n;
  gp_hash_table<string, int> t;
  for (int i = 0; i < n; i++) {
    string s;
    int l; cin >> l;
    s += to_string(l) + " ";
    for (int j = 0; j < l; j++) {
      int li; cin >> li;
      s += to_string(li) + " ";
    }
    //cout << s << '\n' << endl;
    t[s]++;
  }
  cout << t.size() << endl;
  return 0;
}
