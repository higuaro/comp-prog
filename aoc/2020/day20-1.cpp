#include <bits/stdc++.h>
using namespace std;
uint64_t to_state(const vector<string>& t) {
  const int N = 10;
  array<int, 4> w; w.fill(0);
  for (int i = 0; i < N; i++) {
    w[0] |= ((t[0][i] == '#' ? 1 : 0) << (9 - i));
    w[3] |= ((t[9][i] == '#' ? 1 : 0) << (9 - i));
    w[1] |= ((t[i][0] == '#' ? 1 : 0) << (9 - i));
    w[2] |= ((t[i][9] == '#' ? 1 : 0) << (9 - i));
  }
  uint64_t r = w[0];
  r <<= 10; r |= w[1];
  r <<= 10; r |= w[2];
  r <<= 10; r |= w[3];
  return r;
}
string to_str(const uint64_t s) {
  const int N = 10;
  vector<string> t(N, string(N, ' '));
  array<int, 4> w; w.fill(0);
  w[0] = s >> 30;
  w[1] = (s >> 20) & 0x03ff;
  w[2] = (s >> 10) & 0x03ff;
  w[3] = s & 0x03ff;
  for (int i = 0; i < N; i++) {
    t[0][i] = (w[0] >> (9 - i)) & 1 ? '#' : '.';
    t[9][i] = (w[3] >> (9 - i)) & 1 ? '#' : '.';
    t[i][0] = (w[1] >> (9 - i)) & 1 ? '#' : '.';
    t[i][9] = (w[2] >> (9 - i)) & 1 ? '#' : '.';
  }
  string r;
  for (int i = 0; i < N; i++)
    r += t[i] + '\n';
  return r;
}
int main() {
  string line;

  while (getline(cin, line, '\n')) {
    if (line.empty()) continue;
    size_t colon = line.find(':');
    if (colon != string::npos) {
      int tile_id = stoi(line.substr(5, line.size() - 1));
      vector<string> tile;
      while (getline(cin, line, '\n')) {
        if (line.empty()) break;
        tile.push_back(line);
      }
      uint64_t state = to_state(tile);
      string d = to_str(state);
      cout << d << endl;
      exit(1);
    }
  }
  return 0;
}
