#include <bits/stdc++.h>
using namespace std;
struct portal_t {
  int xo, yo;
  int xf, yf;
};
typedef vector<vector<char>> maze_t;
typedef unordered_map<string, portal_t> portals_t;
int ox[] {  0,  1,  0, -1};
int oy[] { -1,  0,  1,  0};
void draw(const maze_t& maze, int W, int H) {
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++)
      cout << maze[y][x];
    cout << endl;
  }
  cout << endl;
}
void seal_dead_ends(maze_t& maze, int W, int H) {
  queue<pair<int, int>> dead_ends;
  do {
    while (!dead_ends.empty()) {
      auto [x, y] = dead_ends.front(); dead_ends.pop();
      maze[y][x] = '#';
    }
    for (int y = 0; y < H; y++)
      for (int x = 0; x < W; x++)
        if (maze[y][x] == '.') {
          int walls = 0;
          for (int k = 0; k < 4; k++) {
            int xx = x + ox[k];
            int yy = y + oy[k];
            if (xx < 0 || xx >= W || yy < 0 || yy >= H) continue;
            walls += maze[yy][xx] == '#';
          }
          if (walls >= 3) dead_ends.emplace(x, y);
        }
  } while (!dead_ends.empty());
}

portals_t scan_portals(const maze_t& maze, int W, int H) {
  portals_t portals;
  // horizontal portals
  for (int y = 0; y < H; y++)
    for (int x = 0; x < W - 1; x++) {
      char ch1 = maze[y][x];
      char ch2 = maze[y][x + 1];
      if (isupper(ch1) && isupper(ch2)) {
        string label{ch1, ch2};
        int open_tile = x && maze[y][x - 1] == '.' ? x - 1 : x + 2;
        if (portals.count(label)) {
          portals[label].xf = open_tile;
          portals[label].yf = y;
        } else {
          portals[label] = {open_tile, y, 0, 0};
        }
      }
    }

  // vertical portals
  for (int y = 0; y < H - 1; y++)
    for (int x = 0; x < W; x++) {
      char ch1 = maze[y][x];
      char ch2 = maze[y + 1][x];
      if (isupper(ch1) && isupper(ch2)) {
        string label{ch1, ch2};
        int open_tile = y && maze[y - 1][x] == '.' ? y - 1 : y + 2;
        if (portals.count(label)) {
          portals[label].xf = x;
          portals[label].yf = open_tile;
        } else {
          portals[label] = {x, open_tile, 0, 0};
        }
      }
    }

  return portals;
}

vector<pair<int, int>> bfs(const maze_t& maze, int W, int H,
    int sx, int sy, int dx, int dy, const portals_t& portals) {
  vector<vector<pair<int, int>>> ports(H, vector<pair<int, int>>(W, {0, 0}));
  for (auto [_, p] : portals) {
    ports[p.yo][p.xo] = {p.xf, p.yf};
    ports[p.yf][p.xf] = {p.xo, p.yo};
  }

  queue<pair<int, int>> q;
  vector<vector<bool>> visited(H, vector<bool>(W, false));
  map<pair<int, int>, pair<int, int>> comes_from;

  q.emplace(sx, sy);
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    auto [x, y] = node;

    if (x == dx && y == dy) {
      vector<pair<int, int>> solution;
      auto [px, py] = node;
      while (px || py) {
        solution.emplace_back(px, py);
        node = comes_from[node];
        px = node.first;
        py = node.second;
      }
      reverse(begin(solution), end(solution));
      return solution;
    }

    for (int k = 0; k < 4; k++) {
      int xx = x + ox[k];
      int yy = y + oy[k];
      if (!(0 <= xx && xx < W && 0 <= yy && yy < H)) continue;
      if (maze[yy][xx] != '.' || visited[yy][xx]) continue;

      pair<int, int> child{xx, yy};
      comes_from[child] = node;
      q.push(child);

      auto p = ports[yy][xx];
      auto [px, py] = p;
      if (px || py) {
        comes_from[p] = child;
        q.push(p);
      }
    }
    visited[y][x] = true;
  }
  return {};
}

int main() {
  ifstream fis("20.in");
  maze_t maze;
  string line;
  while (getline(fis, line, '\n'))
    maze.emplace_back(begin(line), end(line));
  const int W = maze[0].size();
  const int H = maze.size();

  seal_dead_ends(maze, W, H);
  cout << "after sealing dead ends:" << endl;
  draw(maze, W, H);

  auto portals = scan_portals(maze, W, H);
  for (auto [label, portal] : portals)
    cout << "portal " << label << ": " << portal.xo << ',' << portal.yo
        << " -> " << portal.xf << ',' << portal.yf << endl;
  auto [sx, sy, _0, _1] = portals["AA"];
  auto [dx, dy, _2, _3] = portals["ZZ"];
  auto solution = bfs(maze, W, H, sx, sy, dx, dy, portals);

  for (auto [x, y] : solution) {
    if (system("CLS")) system("clear");
    maze[y][x] = '@';
    draw(maze, W, H);
    maze[y][x] = '.';
    this_thread::sleep_for(chrono::milliseconds(100));
  }
  cout << solution.size() - 1 << endl;

  return 0;
}
