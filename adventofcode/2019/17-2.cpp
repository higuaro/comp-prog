#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
enum dir {N, E, S, W};

typedef vector<vector<char>> screen_t;

struct path {
  int robot_r;
  int robot_c;
  dir new_dir;
  string move;
  path(int robot_r, int robot_c, dir new_dir, string move)
    : robot_r(robot_r), robot_c(robot_c), new_dir(new_dir), move(move) {}
};

struct movements_program {
  string routine;
  array<string, 3> functions;
};

std::string replace_all(
    const std::string& str,    // where to work
    const std::string& find,   // substitute 'find'
    const std::string& replace // by 'replace'
) {
  string result;
  size_t find_len = find.size();
  size_t pos, from = 0;
  while (string::npos != (pos = str.find(find, from))) {
    result.append(str, from, pos-from);
    result.append(replace);
    from = pos + find_len;
  }
  result.append( str, from , string::npos );
  return result;
}

pair<bool, vector<string>> compress(const string& path, int depth = 0) {
  istringstream iss(path);
  string line;
  vector<pair<char, int>> moves;
  while (getline(iss, line, ',')) {
    char c = line[0];
    moves.push_back({c, 'A' <= c && c <= 'C' ? 0 : stoi(line.substr(1))});
  }

  unordered_map<string, int> patterns;
  int moves_size = moves.size();
  for (int num_terms = 2; num_terms < 7; num_terms++) {
    for (int wo = 0, wf = num_terms; wf < moves_size; wo++, wf++) {
      ostringstream oss;
      bool first_comma = true;
      bool discard = false;
      for (int w = wo; w < wf; w++) {
        auto m = moves[w];
        auto c = m.first;
        if ('A' <= c && c <= 'C') {
          discard = true; break;
        }
        if (!first_comma) oss << ',';
        first_comma = false;
        oss << m.first << m.second;
      }
      if (!discard) patterns[oss.str()]++;
    }
  }

  string replacement{static_cast<char>('A' + depth)};
  for (auto pattern : patterns) {
    if (pattern.second == 1) continue;
    auto patt = pattern.first;
    string res = replace_all(path, patt, replacement);
    if (depth < 2) {
      auto [found, solution] = compress(res, depth + 1);
      if (found) {
        cerr << replacement << " = " << patt << endl;
        solution.push_back(patt);
        return {found, solution};
      }
    } else {
      if (res.find_first_of("LR") == string::npos) {
        cerr << "compressed: " << res << endl;
        cerr << replacement << " = " << patt << endl;
        return {true, {res, patt}};
      }
    }
  }

  return {false, {}};
}

inline bool is_robot(char c) {
  return c == '<' || c == '^' || c == '>' || c == 'v';
}

inline dir direction(const screen_t& screen, int rob_r, int rob_c) {
  switch (screen[rob_r][rob_c]) {
    case '^': return N;
    case '>': return E;
    case 'v': return S;
    case '<':
    default: return W;
  }
}

string turn_to(const dir cur_dir, const dir new_dir) {
  switch (cur_dir) {
    case N: return new_dir == W ? "L" : "R";
    case E: return new_dir == N ? "L" : "R";
    case S: return new_dir == E ? "L" : "R";
    case W:
    default: return new_dir == S ? "L" : "R";
  }
}

path find_longest(const screen_t& screen,
    const int rob_r, const int rob_c, dir cur_dir, set<pair<int, int>>& visited) {
  int rows = screen.size();
  int cols = screen[0].size();
  int offset_r[]{-1, 0, 1, 0};
  int offset_c[]{ 0, 1, 0, -1};
  array<int, 4> distances; distances.fill(0);
  for (size_t k = 0; k < 4; k++) {
    int r = rob_r + offset_r[k];
    int c = rob_c + offset_c[k];
    while (0 <= r && r < rows && 0 <= c && c < cols
        && !visited.count({r, c})) {
      char ch = screen[r][c];
      if (ch != '#') break;
      distances[k]++;
      r += offset_r[k];
      c += offset_c[k];
    }
  }

  int max = 0;
  dir max_dir = N;
  for (size_t k = 0; k < 4; k++)
    if (distances[k] > max) {
      max = distances[k];
      max_dir = static_cast<dir>(k);
    }

  int new_rob_r = rob_r + offset_r[max_dir] * max;
  int new_rob_c = rob_c + offset_c[max_dir] * max;
  visited.insert({
    new_rob_r - offset_r[max_dir],
    new_rob_c - offset_c[max_dir]
  });

  if (!max) {
    return {rob_r, rob_c, cur_dir, ""};
  }

  string movement = turn_to(cur_dir, max_dir) + to_string(max);
  return {new_rob_r, new_rob_c, max_dir, movement};
}

string visit_scaffold(const screen_t& screen) {
  size_t rows = screen.size();
  size_t cols = screen[0].size();
  size_t robot_r = 0, robot_c = 0;
  for (size_t r = 0; r < rows; r++) {
    bool found = false;
    for (size_t c = 0; c < cols; c++) {
      if (is_robot(screen[r][c])) {
        robot_r = r; robot_c = c;
        found = true;
        break;
      }
    }
    if (found) break;
  }

  dir cur_dir = direction(screen, robot_r, robot_c);

  set<pair<int, int>> visited;
  string movements;
  string move;
  do {
    auto path = find_longest(screen, robot_r, robot_c, cur_dir, visited);

    robot_r = path.robot_r;
    robot_c = path.robot_c;
    cur_dir = path.new_dir;
    move = path.move;

    if (movements != "" && move != "") movements += ',';
    movements += move;
  } while (move != "");

  return movements;
}

int main() {
  screen_t screen;
  vector<char> current_row;

  ifstream program_file("17.in");
  auto program = intcode::parse_rom(program_file);
  program[0] = 2;

  bool solution_mode = false;
  string solution;
  int cleaned = 0;
  int solution_input_index = 0;
  string solution_output;

  intcode mac{program,
    [&]() -> int64_t {
      return solution[solution_input_index++];
    },
    [&](int64_t v) {
      if (solution_mode) {
        if (v > 255)
          cleaned = v;
        else
          solution_output += static_cast<char>(v);
        return;
      }
      char c = static_cast<char>(v);
      if (c == '\n') {
        if (current_row.size())
          screen.push_back(current_row);
        else {
          auto movements = visit_scaffold(screen);
          cout << "\nmovements: " << movements << endl;

          auto [_, sol] = compress(movements);
          swap(sol[1], sol[3]);
          for (auto line : sol) {
            vector<char> input_line;
            for (auto c : line) {
              input_line.push_back(c);
              if (c == 'L' || c == 'R')
                input_line.push_back(',');
            }
            input_line.push_back(10);
            solution += string(begin(input_line), end(input_line));
          }
          solution += "n\n";
          solution_mode = true;
        }
        current_row.clear();
        return;
      }
      current_row.push_back(c);
    }
  };

  mac.run();

  vector<pair<int, int>> intersections;
  int offset_row[]{0, -1, 0, 1};
  int offset_col[]{-1, 0, 1, 0};
  size_t h = screen.size();
  for (size_t r = 0; r < h; r++) {
    auto& row = screen[r];
    size_t w = row.size();
    for (size_t c = 0; c < w; c++) {
      char ch = row[c];
      if (ch != '#' && !is_robot(ch)) continue;

      size_t blocks = 0;
      for (int k = 0; k < 4; k++) {
        int R = r + offset_row[k];
        int C = c + offset_col[k];
        if (R < 0 || R >= static_cast<int>(h)
            || C < 0 || C >= static_cast<int>(w))
          continue;
        if (screen[R][C] == '#') blocks++;
      }
      if (blocks == 4)
        intersections.push_back({r, c});
    }
  }

  int sum = 0;
  for (auto inter : intersections) {
    sum += inter.first * inter.second;
  }

  cout << solution_output << endl;
  cout << "Finally, the solution to this fucking piece of shit problem is: "
    << cleaned << endl;
}
