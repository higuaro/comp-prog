#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
  vector<string> a;
  string s;
  int k = 0;
  while (cin >> s) {
    a.push_back(s);
    k = s.size();
  }

  vector<pair<int, int>> bits(k, {0, 0});
  for (int i = 0; i < a.size(); i++) {
    string ai = a[i];
    for (int j = 0; j < k; j++) {
      if (ai[j] == '1') 
        bits[j].second++; 
      else 
        bits[j].first++;
    }
  }
  int max_g = 0;
  int min_g = 0;
  for (int i = k - 1, j = 0; i >= 0; i--, j++) {
    cout << bits[i].first << ' ' << bits[i].second << endl;
    int b = bits[i].second > bits[i].first ? 1 : 0;
    max_g |= (b << j);
    min_g |= ((1 - b) << j);
  }
  //cout << bitset<5>(max_g).to_string() << ' ' << bitset<5>(min_g).to_string() << endl;
  cout << min_g * max_g << endl;
  return 0;
}
