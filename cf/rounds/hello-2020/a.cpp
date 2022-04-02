#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  int m; cin >> m;
  vector<string> ns, ms;
  string line;
  cin.ignore(256, '\n');
  getline(cin, line, '\n');
  istringstream iss(line);
  string word;
  while (getline(iss, word, ' ')) 
    ns.push_back(word);
  getline(cin, line, '\n');
  istringstream iss2(line);
  while (getline(iss2, word, ' '))
    ms.push_back(word);
  int q; cin >> q;
  while (q--) {
    int y; cin >> y;
    y--;
    cout << ns[y % ns.size()] << ms[y % ms.size()] << endl;
  }
  return 0;
}
