#include <bits/stdc++.h>
using namespace std;
const int A = 128;
const int N = 100;
const int ox[] = {-1, 0, 1, 0};
const int oy[] = { 0,-1, 0, 1};
int W, H, K;

string s[N];
set<char> symbols;
pair<int, int> coords[A];
array<tuple<int, int, int>, A> distances;

void draw() {
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++)
      cout << s[y][x];
    cout << endl;
  }
}

void seal_dead_ends() {
  queue<pair<int, int>> dead_ends;
  do {
    while (!dead_ends.empty()) {
      auto [x, y] = dead_ends.front();
      dead_ends.pop();
      s[y][x] = '#';
    }
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        if (s[y][x] != '.' &&
            !isupper(s[y][x])) continue;
        int walls = 0;
        for (int i = 0; i < 4; i++) {
          int xx = x + ox[i];
          int yy = y + oy[i];
          walls += s[yy][xx] == '#';
        }
        if (walls > 2) dead_ends.push({x, y});
      }
    }
  } while (!dead_ends.empty());
}

void precompute_dists() {
  distances.fill({0, 0, 0});
  set<char> visited;
  for (auto s1 : symbols) {
    for (auto s2 : symbols) {
      if (s1 == s2 || visited.count(s2)) continue;
      { // bfs

      }
    }
    visited.insert(s1);
  }
}

int main() {
  ifstream fis("18.in");
  while (fis >> s[H])
    H += !s[H].empty();
  W = s[0].size();

  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) {
      char c = s[i][j];
      if (c != '#' && c != '.') {
        coords[static_cast<int>(c)] = {i, j};
        symbols.insert(c);
      }
      K += 'a' <= c && c <= 'z';
    }

  seal_dead_ends();



  return 0;
}
