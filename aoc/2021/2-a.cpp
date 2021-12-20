#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
  string s; int n;
  int x, y; x = y = 0;
  while (cin >> s) {
    cin >> n;
    if (s == "forward") 
      x += n;
    else if (s == "up") 
      y -= n;
    else
      y += n;
  }
  cout << x << ' ' << y << ' ' << x * y << endl;
  return 0;
}
