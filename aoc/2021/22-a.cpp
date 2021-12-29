#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
//typedef unordered_map<int, unordered_map<int, unordered_map<int, bool>>> cube_t;
typedef map<tuple<int, int, int>, bool> cube_t;
void remove_any(string& s, const string& r) {
  for (char c : r)
    replace(begin(s), end(s), c, ' ');
}
int main() {
  string line;
  cube_t cube;
  while (getline(cin, line)) {
    remove_any(line, "=.,xyz");
    istringstream iss(line);
    int min_x, max_x, min_y, max_y, min_z, max_z;
    string is_on;
    iss >> is_on >> min_x >> max_x >> min_y >> max_y >> min_z >> max_z;
    if (-50 <= min_x && min_x <= 50 
        && -50 <= min_y && min_y <= 50 
        && -50 <= min_z && min_z <= 50) {
      for (int x = min_x; x <= max_x; x++) 
        for (int y = min_y; y <= max_y; y++) 
          for (int z = min_z; z <= max_z; z++) 
            cube[{x, y, z}] = is_on == "on";
    }
  }
  int total_on = 0; 
  for (auto [_, on] : cube)
    if (on) total_on++;
  cout << total_on << endl;
  return 0;
}
