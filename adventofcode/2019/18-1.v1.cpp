#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> board_t;
typedef unordered_map<char, pair<int, int>> coordinates_t;
typedef unsigned int uint;

int offset_y[]{ -1,  0,  1,  0};
int offset_x[]{  0,  1,  0, -1};

void draw(const vector<vector<char>>& maze) {
  for (size_t row = 0; row < maze.size(); row++) {
    auto r = maze[row];
    auto cols = r.size();
    for (size_t col = 0; col < cols; col++)
      cout << r[col];
    cout << endl;
  }
  cout << endl;
}

struct node_t {
  uint64_t state;
  uint64_t parent;
  int steps;

  static const uint64_t ox = 21;
  static const uint64_t oy = 14;
  static const uint64_t opx = 7;
  static const uint64_t opy = 0;
  static const int coord_mask = 127;
  static const int keys_mask = (1 << 26) - 1;

  node_t(int x, int y, int keys = 0, uint64_t parent = 0, int steps = 0)
    : state(calc_state(keys, x, y, parent)), parent(parent), steps(steps) {}

  static uint64_t calc_state(int keys, int x, int y, uint64_t parent_state) {
    auto [px, py] = coord(parent_state);
    uint64_t c = (x << ox) | (y << oy) | (px << opx) | (py << opy);
    c <<= 32;
    return c | keys;
  }

  static pair<int, int> coord(const uint64_t state) {
    int c = state >> 32;
    return {(c >> ox) & coord_mask, (c >> oy) & coord_mask};
  }

  pair<int, int> parent_coords() const {
    int c = state >> 32;
    return {(c >> opx) & coord_mask, (c >> opy) & coord_mask};
  }

  int keys() const {
    return keys_mask & state;
  }

  pair<int, int> coords() const {
    return coord(state);
  }
};

bool is_door_closed(char door, int keys) {
  char key = tolower(door);
  int key_index = static_cast<int>(key - 'a');
  return !(keys >> key_index & 1);
}

vector<pair<int, int>> bfs(const board_t& maze, const coordinates_t& key_map,
    const int ply_x, const int ply_y, const int W, const int H) {
  queue<node_t> q;
  unordered_map<uint64_t, pair<int, uint64_t>> explored;

  int num_keys = key_map.size();

  int best = 10000;
  vector<pair<int, int>> best_solution;

  q.push({ply_x, ply_y});
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    int node_keys = node.keys();

    if (__builtin_popcount(node_keys) == num_keys) {
      vector<pair<int, int>> solution{node.coords()};
      uint64_t parent = node.parent;
      while (parent != 0) {
        solution.push_back(node_t::coord(parent));
        parent = explored[parent].second;
      }
      solution.pop_back();
      reverse(begin(solution), end(solution));
      if (static_cast<int>(solution.size()) < best) {
        clog << "found a solution with size: " << solution.size() << endl;
        best_solution = move(solution);
        best = best_solution.size();
      }
      continue;
    }

    for (int i = 0; i < 4; i++) {
      auto [node_x, node_y] = node.coords();
      int x = node_x + offset_x[i];
      int y = node_y + offset_y[i];

      if (node.steps > best) continue;

      // boundaries
      if (x < 0 || x >= W || y < 0 || y >= H) continue;

      // walls
      char ch = maze[y][x];
      if (ch == '#') continue;

      // closed doors
      if (isupper(ch) && is_door_closed(ch, node.keys())) continue;

      int keys = islower(ch) ? 1 << (ch - 'a') : 0;
      keys |= node_keys;

      node_t new_node{x, y, keys, node.state, node.steps + 1};
// cerr << new_node.state << endl;

      // visited
      if (explored.count(new_node.state)
        && explored[new_node.state].first < new_node.steps) continue;

      q.push(new_node);
    }

    explored[node.state] = {node.steps, node.parent};
  }
  return best_solution;
}

void seal_dead_ends(board_t& maze, const int W, const int H) {
  queue<pair<int, int>> dead_ends;
  do {
    while (!dead_ends.empty()) {
      auto [x, y] = dead_ends.front();
      dead_ends.pop();
      maze[y][x] = '#';
    }
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        char ch = maze[y][x];
        if (ch != '.' && !isupper(ch)) continue;
        int walls = 0;
        for (int k = 0; k < 4; k++) {
          int xx = x + offset_x[k];
          int yy = y + offset_y[k];
          walls += maze[yy][xx] == '#';
        }
        if (walls == 3) dead_ends.push({x, y});
      }
    }
  } while (!dead_ends.empty());
}

int main() {
  ifstream fis("18.in");
  auto prev_buf = cin.rdbuf();
  cin.rdbuf(fis.rdbuf());

  board_t maze;
  coordinates_t doors;
  coordinates_t key_map;
  int ply_x, ply_y;
  string line;
  while (getline(cin, line, '\n')) {
    vector<char> maze_line;
    int row = maze.size();
    for (size_t col = 0; col < line.size(); col++) {
      char c = line[col];
      maze_line.push_back(c);
      if (c == '@') {
        ply_x = col;
        ply_y = row;
      }
      if (isupper(c))
        doors[c] = {col, row};
      if (islower(c)) 
        key_map[c] = {col, row};
    }
    maze.push_back(maze_line);
  }
  const int W = maze[0].size();
  const int H = maze.size();

  seal_dead_ends(maze, W, H);
  cout << "maze after sealing dead-ends:" << endl;
  draw(maze);

  auto solution = bfs(maze, key_map, ply_x, ply_y, W, H);

  cout << "solution steps: " << solution.size() << endl;
 

  cout << "play animation? [y/n and ENTER] ";
  cin.rdbuf(prev_buf);
  char input; cin >> input;
  if (input != 'y') return 0;

  maze[ply_y][ply_x] = '.';
  for (auto p : solution) {
    auto [x, y] = p;
    maze[y][x] = '@';
    if (system("CLS")) system("clear");
    draw(maze);
    maze[y][x] = '.';
    this_thread::sleep_for(chrono::milliseconds(50));
  }
  cout << "solution steps: " << solution.size() << endl;

  return 0;
}
