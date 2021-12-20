#include <bits/stdc++.h>
using namespace std;
uint to_int(const string& s) {
  int r = 0;
  int b = 1;
  for (int i = s.size() - 1; i >= 0; i--, b *= 2)
    r += static_cast<int>(s[i] - '0') * b;
  return r;
}

int main() {
  int size = 100;
  const int SIZE = size * 3;
  vector<vector<char>> input(SIZE, vector<char>(SIZE, '.'));
  vector<vector<char>> output(SIZE, vector<char>(SIZE, '.'));
  string algorithm; cin >> algorithm;
  string line;
  int yy = 0;
  while (getline(cin, line)) {
    if (line == "") continue;
    for (int x = 0; x < line.size(); x++)
      input[yy + size][x + size] = line[x];
    yy++;
  }

  for (int step = 0; step < 50; step++) {
    for (int y = 0; y < SIZE; y++) {
      for (int x = 0; x < SIZE; x++) {
        string index;
        for (int p = -1; p <= 1; p++) {
          for (int q = -1; q <= 1; q++) {
            int yy = y + p;
            int xx = x + q;
            if (0 <= yy && yy < SIZE && 0 <= xx && xx < SIZE) {
              index += input[yy][xx] == '#' ? '1' : '0';
            } else {
              index += (step & 1 ? '1' : '0');
            }
          }
        }
        output[y][x] = algorithm[to_int(index)];
      }
    }
    input = output;
  }

  int lit = 0;
  for (int y = 0; y < SIZE; y++)
    for (int x = 0; x < SIZE; x++)
      if (output[y][x] == '#') lit++;
  cout << lit << endl;
  return 0;
}
