#include <bits/stdc++.h>
using namespace std;
struct portal_t {
  int xo, yo;
  int xf, yf;
};
typedef vector<vector<char>> maze_t;
typedef unordered_map<string, portal_t> portals_t;
int oy[] = {-1, 0, 1, 0};
int ox[] = { 0, 1, 0,-1};

void draw(const maze_t& maze, int W, int H) {
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++)
      cout << maze[y][x];
    cout << endl;
  }
}

void seal_dead_ends(maze_t& maze, int W, int H) {
  queue<pair<int, int>> dead_ends;
  do {
    while (!dead_ends.empty()) {
      auto [x, y] = dead_ends.front(); dead_ends.pop();
      maze[y][x] = '#';
    }
    for (int y = 0; y < H; y++)
      for (int x = 0; x < W; x++) {
        if (maze[y][x] != '.') continue;
        int walls = 0;
        for (int k = 0; k < 4; k++) {
          int xx = x + ox[k];
          int yy = y + oy[k];
          if (xx < 0 || xx >= W || yy < 0 || yy >= H) continue;
          if (maze[yy][xx] == '#') walls++;
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

vector<tuple<int, int, int>> find_path(const maze_t& maze, int W, int H,
    int sx, int sy, int dx, int dy, const portals_t& scanned_portals) {
  vector<pair<int, int>> portals(H * W, {0, 0});
  for (auto [_, p] : scanned_portals) {
    portals[p.yo * H + p.xo] = {p.xf, p.yf};
    portals[p.yf * H + p.xf] = {p.xo, p.yo};
  }
  queue<tuple<int, int, int>> q;
  vector<set<int>> visited(H * W, set<int>());
  map<tuple<int, int, int>, tuple<int, int, int>> comes_from;

  q.emplace(sx, sy, 0);
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    const auto [x, y, d] = node;

    if (x == dx && y == dy && !d) {
      cout << "found a solution" << endl;
      vector<tuple<int, int, int>> solution;
      auto [px, py, pd] = node;
      while (px || py || pd) {
        solution.emplace_back(px, py, pd);
        node = comes_from[node];
        px = get<0>(node);
        py = get<1>(node);
        pd = get<2>(node);
      }
      reverse(begin(solution), end(solution));
      return solution;
    }

    for (int k = 0; k < 4; k++) {
      int xx = x + ox[k];
      int yy = y + oy[k];
      if (xx < 0 || xx >= W || yy < 0 || yy >= H) continue;
      if (maze[yy][xx] != '.' || visited[yy * H + xx].count(d)) continue;
      
      tuple<int, int, int> child{xx, yy, d};
      comes_from[child] = node;
      q.push(child);

      auto p = portals[yy * H + xx];
      auto [px, py] = p;
      if (px || py) {
        bool inner = 2 < xx && xx < W - 3 && 2 < yy && yy < H - 3;
        int level = inner ? d + 1 : d - 1;
        if (level < 0) continue;
        tuple<int, int, int> t{px, py, level};
        comes_from[t] = child;
        q.push(t);
      }
    }
    visited[y * H + x].insert(d);
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

  auto s = portals["AA"];
  auto d = portals["ZZ"];
  auto path = find_path(maze, W, H, s.xo, s.yo, d.xo, d.yo, portals);

  for (auto [x, y, d] : path) {
    if (system("CLS")) system("clear");
    maze[y][x] = static_cast<char>(d + '0');
    draw(maze, W, H);
    maze[y][x] = '.';
    this_thread::sleep_for(chrono::milliseconds(100));
  }
  if (path.size())
    cout << "steps = " << path.size() - 1 << endl;
  else
    cout << "no solution found" << endl;

  return 0;
}
