#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> board_t;
typedef unordered_map<char, pair<int, int>> coordinates_t;

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
  int x, y;
  int keys;
  int steps, h, f;
  shared_ptr<node_t> parent;
  node_t(const coordinates_t& key_map,
      int x, int y, int keys, int steps, shared_ptr<node_t> parent = nullptr)
    : x(x), y(y), keys(keys), steps(steps), parent(parent) {
    int h = 0;
    for (auto e : key_map) {
      auto k = e.first;
      int index = static_cast<int>(k - 'a');
      if (!(keys >> index & 1)) {
        auto [kx, ky] = e.second;
        // h += abs(kx - x) + abs(ky - y) + 100;
        h += 1000;
      }
    }
    this->h = h;
    this->f = h + 100 * steps;
  }
};

bool is_door_open(char door, int keys) {
  char key = tolower(door);
  int key_index = static_cast<int>(key - 'a');
  return (keys >> key_index) & 1;
}

vector<pair<int, int>> a_star(const board_t& maze, const coordinates_t& key_map,
    const int ply_x, const int ply_y, const int W, const int H) {
  auto cmp = [](const auto& n1, const auto& n2) {
    return n1->f < n2->f;
  };
  priority_queue<shared_ptr<node_t>, vector<shared_ptr<node_t>>, decltype(cmp)>
    open(cmp);
  map<pair<int, int>, int> closed;
  // set<tuple<int, int, int>> closed;

  int best_solution_size = numeric_limits<int>::max();
  vector<pair<int, int>> best_solution;

  open.push(make_shared<node_t>(key_map, ply_x, ply_y, 0, 0));
  while (!open.empty()) {
    auto node = open.top(); open.pop();

    if (node->steps >= best_solution_size) continue;

    if (__builtin_popcount(node->keys) == key_map.size()) {
      vector<pair<int, int>> solution;
      while (node->parent != nullptr) {
        solution.push_back({node->x, node->y});
        node = node->parent;
      }
      reverse(begin(solution), end(solution));
      if (solution.size() < best_solution_size) {
cerr << "found a solution with size: " << solution.size() << endl;
        best_solution = move(solution);
        best_solution_size = best_solution.size();
cerr << "best solution so far: " << best_solution_size << endl;
      }
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int x = node->x + offset_x[i];
      int y = node->y + offset_y[i];
      if (node->parent != nullptr)
        if (x == node->parent->x && y == node->parent->y) 
          continue;

      if (x < 0 || x >= W || y < 0 || y >= H) continue;
      char ch = maze[y][x];
      if (ch == '#') continue;
      if (isupper(ch) && !is_door_open(ch, node->keys)) continue;
      int keys = islower(ch) ? 1 << (ch - 'a') : 0;
      keys |= node->keys;
      auto n = make_shared<node_t>(key_map, x, y, keys, node->steps + 1, node);
      if (closed.count({x, y}) && n->h >= closed[{x, y}]) continue;
      // if (closed.count({x, y, n->f})) continue;
      open.push(make_shared<node_t>(key_map, x, y, keys, node->steps + 1, node));
    }
    closed[{node->x, node->y}] = node->h;
    // closed.insert({node->x, node->y, node->f});
  }
  return best_solution;
}

int main() {
  ifstream fis("18.in");
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

  draw(maze);
  cout << "#doors: " << doors.size() << ", #keys: " << key_map.size() << endl;

  auto solution = a_star(maze, key_map, ply_x, ply_y, W, H);

  maze[ply_y][ply_x] = '.';
  for (auto p : solution) {
    auto [x, y] = p;
    maze[y][x] = '@';
    draw(maze);
    maze[y][x] = '.';
  }
  cout << solution.size() << endl;

  return 0;
}
