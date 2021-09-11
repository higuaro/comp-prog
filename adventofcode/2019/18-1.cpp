#include <bits/stdc++.h>
using namespace std;

const int ALPH_SIZE = 26 + 1;

typedef vector<vector<char>> board_t;
typedef unordered_map<char, pair<int, int>> coordinates_t;
typedef array<array<tuple<int, int, int>, ALPH_SIZE>, ALPH_SIZE> distances_t;

const int offset_y[]{ -1,  0,  1,  0};
const int offset_x[]{  0,  1,  0, -1};

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

// Returns the steps, the keys required, and the keys collected along the way
tuple<int, int, int> bfs(const board_t& maze, const int W, const int H, 
    int sx, int sy, int dx, int dy) {
  struct node_t {
    int64_t state;
    node_t(int64_t state) : state(state) {}
    node_t(int x, int y, int px = 0, int py = 0, int doors = 0) {
      int64_t s = x << 7 | y;
      s <<= 14;
      s |= px << 7 | py;
      s <<= 26;
      this->state = s | doors;
    }
    int x() const { return (state >> 26) >> 21; }
    int y() const { return ((state >> 26) >> 14) & ((1 << 7) - 1); }
    int doors() const {
      static const int K = (1 << 26) - 1;
      return state & K;
    }
  };
  queue<node_t> q;
  unordered_set<int64_t> visited;
  unordered_map<int64_t, int64_t> parents;

  q.push({sx, sy});
  while (!q.empty()) {
    auto node = q.front(); q.pop();
    int x = node.x();
    int y = node.y();
    int doors = node.doors();

    if (x == dx && y == dy) {
      char ch = 0;
      int steps = 0;
      int keys_collected = 0;
      node = parents[node.state];
      int nx = node.x(); int ny = node.y();
      while (nx || ny) {
        ch = maze[ny][nx];
        keys_collected |= islower(ch) ? 1 << static_cast<int>(ch - 'a') : 0;
        node = parents[node.state];
        nx = node.x();
        ny = node.y();
        steps++;
      }
      ch = maze[sy][sx];
      if (islower(ch)) keys_collected ^= (1 << static_cast<int>(ch - 'a'));

      return {steps, doors, keys_collected};
    }

    for (int n = 0; n < 4; n++) {
      int nx = x + offset_x[n];
      int ny = y + offset_y[n];
      int d = doors;

      if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
      char ch = maze[ny][nx];
      if (ch == '#') continue;
      if (isupper(ch)) d |= (1 << static_cast<int>(ch - 'A'));
      node_t s{nx, ny, x, y, d};
      if (visited.count(s.state)) continue;
      parents[s.state] = node.state;
      q.push(s);
    }
    visited.insert(node.state);
  }

  return {0, 0, 0};
}

distances_t precompute_distances(const board_t& maze, const int W, const int H,
    const int ply_x, const int ply_y, coordinates_t& key_map) {
  distances_t distances;
  vector<char> symbols{'@'};
  for (auto e : key_map) symbols.push_back(e.first);

  for (int i = 0; i < symbols.size(); i++) {
    int sx, sy;
    char source = symbols[i];
    if (source == '@') {
      sx = ply_x;
      sy = ply_y;
    } else {
      auto coords = key_map[source];
      sx = coords.first;
      sy = coords.second;
    }
    for (int j = i + 1; j < symbols.size(); j++) {
      char destination = symbols[j];
      int dx, dy;
      if (destination == '@') {
        dx = ply_x;
        dy = ply_y;
      } else {
        auto coords = key_map[destination];
        dx = coords.first;
        dy = coords.second;
      }
      auto dist = bfs(maze, W, H, sx, sy, dx, dy);
      distances[source][destination] = dist;
      distances[destination][source] = dist;
    }
  }
  return distances;
}

vector<char> find_path(const board_t& maze, const int W, const int H, 
    int ply_x, int ply_y, coordinates_t& key_map, distances_t& distances) {
  struct node_t {
    int64_t state;
    int steps;
    node_t() : state(0), steps(0) {}
    node_t(int64_t state, int steps = 0) : state(state), steps(steps) {}
    node_t(int x, int y, int steps = 0, char comes_from = 0, int keys = 0) 
     : steps(steps) {
      int64_t s = x << 7;
      s |= y; s <<= 8;
      s |= static_cast<int>(comes_from); s <<= 26;
      this->state = s | keys;
    }
    int x() const { return (state >> 26) >> 15; }
    int y() const { return ((state >> 26) >> 8) & ((1 << 7) - 1); }
    char comes_from() const { return (state >> 26) & 0xff; }
    int keys() const {
      static const int K = (1 << 26) - 1;
      return state & K;
    }
    bool operator<(const node_t& n) const {
      return this->state == n.state 
        ? this->steps < n.steps 
        : this->state < n.state;
    }
  };

  unordered_set<int64_t> visited;
  map<node_t, node_t> parents;

  map<pair<int, int>, char> rev_key_map;
  for (auto e : key_map) rev_key_map[e.second] = e.first;
  rev_key_map[{ply_x, ply_y}] = '@';

  vector<char> best_solution;
  int min_steps = numeric_limits<int>::max();

  int num_keys = key_map.size();

  queue<node_t> q;
  q.push({ply_x, ply_y});

  while (!q.empty()) {
    const auto node = q.front(); q.pop();
    const int x = node.x();
    const int y = node.y();
    const int keys = node.keys();
    const char current = rev_key_map[{x, y}];

    if (__builtin_popcount(keys) == num_keys && node.steps < min_steps) {
      vector<char> solution;
      node_t n = node;
      char current = 0;
      char comes_from = 1;
      while (comes_from) {
        comes_from = n.comes_from();
        current = rev_key_map[{n.x(), n.y()}];
        solution.push_back(current);
        n = parents[n];
      }
      reverse(begin(solution), end(solution));
      best_solution = move(solution);
      min_steps = node.steps;
      cerr << "Found solution with " << min_steps << " steps" << endl;
for (auto c : best_solution) clog << c << "->";
clog << endl;
      continue;
    }

    for (int n = 0; n < num_keys; n++) {
      char destination = static_cast<char>(n + 'a');
      if (destination == current) continue;
      auto [steps, doors, keys_collected] = distances[current][destination];
      if (doors && (keys & doors) != doors) continue;
      auto [dx, dy] = key_map[destination];
      int k = (1 << static_cast<int>(n)) | keys | keys_collected;
      node_t child{dx, dy, node.steps + steps, current, k};
      if (visited.count(child.state)) continue;
      parents[child] = node;
      q.push(child);
    }

    visited.insert(node.state);
  }
  return best_solution;
}

string to_str(int doors, char base = 'a') {
  ostringstream oss;
  for (int i = 0; i < 26; i++) {
    if (doors & (1 << i))
      oss << static_cast<char>(i + base);
  }
  return oss.str();
}

void print_sol(board_t& maze, vector<char>& solution,
    coordinates_t& key_map, int ply_x, int ply_y) {
  cout << "solution steps: " << solution.size() << endl;

  cout << "play animation? [y/n and ENTER] ";
  char input; cin >> input;
  if (input != 'y') return;

  maze[ply_y][ply_x] = '.';
  for (auto c : solution) {
    if (c == '@') continue;
    auto [x, y] = key_map[c];
    maze[y][x] = '@';
    if (system("CLS")) system("clear");
    draw(maze);
    maze[y][x] = '.';
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
  cout << "solution steps: " << solution.size() << endl;
}

int main() {
  ifstream fis("18.in");
  auto prev_buf = cin.rdbuf();
  cin.rdbuf(fis.rdbuf());

  board_t maze;
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
      if (islower(c)) key_map[c] = {col, row};
    }
    maze.push_back(maze_line);
  }
  cin.rdbuf(prev_buf);

  const int W = maze[0].size();
  const int H = maze.size();

  seal_dead_ends(maze, W, H);
  cout << "maze after sealing dead-ends:" << endl;
  draw(maze);

  auto distances = precompute_distances(maze, W, H, ply_x, ply_y, key_map);
  auto solution = find_path(maze, W, H, ply_x, ply_y, key_map, distances);

  print_sol(maze, solution, key_map, ply_x, ply_y);

  return 0;
}
