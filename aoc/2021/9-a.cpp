#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;

int main() {
  vector<string> lines;
  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }
  int h = lines.size();
  int w = lines[0].size();
  int risk = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c = lines[i][j];
      int o[] = {-1, 0, 1, 0, -1};
      bool is_low = true;
      for (int k = 0; k < 4; k++) {
        int ii = i + o[k];
        int jj = j + o[k + 1];
        if (0 <= ii && ii < h && 0 <= jj && jj < w) {
          if (lines[ii][jj] <= c) {
            is_low = false;
            break;
          }
        }
      }
      if (is_low) {
        cout << c << endl;
        risk += (c - '0' + 1);
      }
    }
  }
  cout << risk << endl;
  return 0;
}
