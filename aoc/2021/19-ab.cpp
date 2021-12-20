#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> point_t;
typedef pair<uint, pair<int, int>> edge_t;
//          distance   point a         point b
//             V          V               V
typedef tuple<uint, pair<int, int>, pair<int, int>> overlap_t;
typedef unordered_map<int, vector<int>> path_t;

double inline sqr(int n) { return n * n; }

struct scanner_t {
  vector<point_t> points;
  set<edge_t> dist;

  void calc_dist() {
    dist.clear();
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1;j < points.size(); j++) {
        auto [x1, y1, z1] = points[i];
        auto [x2, y2, z2] = points[j];
        auto d2 = sqr(x2 - x1) + sqr(y2 - y1) + sqr(z2 - z1);
        dist.insert({d2, {i, j}});
      }
    }
  }

  set<overlap_t> overlapping_dist(const scanner_t& other) const {
    set<overlap_t> o;
    for (auto d : dist) {
      auto it = find_if(other.dist.begin(), other.dist.end(), 
          [d](edge_t e) { return get<0>(e) == get<0>(d); });
      if (it != end(other.dist))
        o.insert({get<0>(d), get<1>(d), get<1>(*it)});
    }
    return o;
  }
};

struct space_t {
  int to;
  int from;
  int mode;
  point_t scanner_pos;
};

string to_str(const point_t& p) {
  auto [x, y, z] = p;
  ostringstream oss;
  oss << "(" << x << "," << y << "," << z << ")";
  return oss.str();
}

uint manhattan_dist(const point_t& p1, const point_t& p2) {
  auto [x1, y1, z1] = p1;
  auto [x2, y2, z2] = p2;
  return abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
}

point_t add(const point_t& p1, const point_t& p2) {
  auto [x1, y1, z1] = p1;
  auto [x2, y2, z2] = p2;
  return {x1 + x2, y1 + y2, z1 + z2};
}

point_t sub(const point_t& p1, const point_t& p2) {
  auto [x1, y1, z1] = p1;
  auto [x2, y2, z2] = p2;
  return {x1 - x2, y1 - y2, z1 - z2};
}

bool equal(const point_t& p1, const point_t& p2) {
  auto [x1, y1, z1] = p1;
  auto [x2, y2, z2] = p2;
  return x1 == x2 && y1 == y2 && z1 == z2;
}

point_t transform(const point_t& p, int mode) {
  auto [x, y, z] = p;
  switch (mode) {
    case 0: return {x, y, z};
    case 1: return {x, y, -z};
    case 2: return {x, -y, z};
    case 3: return {x, -y, -z};
    case 4: return {-x, y, z};
    case 5: return {-x, y, -z};
    case 6: return {-x, -y, z};
    case 7: return {-x, -y, -z};
    case 8: return {z, x, y};
    case 9: return {z, x, -y};
    case 10: return {z, -x, y};
    case 11: return {z, -x, -y};
    case 12: return {-z, x, y};
    case 13: return {-z, x, -y};
    case 14: return {-z, -x, y};
    case 15: return {-z, -x, -y};
    case 16: return {y, z, x};
    case 17: return {y, z, -x};
    case 18: return {y, -z, x};
    case 19: return {y, -z, -x};
    case 20: return {-y, z, x};
    case 21: return {-y, z, -x};
    case 22: return {-y, -z, x};
    case 23: return {-y, -z, -x};
    case 24: return {x, z, y};
    case 25: return {x, z, -y};
    case 26: return {x, -z, y};
    case 27: return {x, -z, -y};
    case 28: return {-x, z, y};
    case 29: return {-x, z, -y};
    case 30: return {-x, -z, y};
    case 31: return {-x, -z, -y};
    case 32: return {y, x, z};
    case 33: return {y, x, -z};
    case 34: return {y, -x, z};
    case 35: return {y, -x, -z};
    case 36: return {-y, x, z};
    case 37: return {-y, x, -z};
    case 38: return {-y, -x, z};
    case 39: return {-y, -x, -z};
    case 40: return {z, y, x};
    case 41: return {z, y, -x};
    case 42: return {z, -y, x};
    case 43: return {z, -y, -x};
    case 44: return {-z, y, x};
    case 45: return {-z, y, -x};
    case 46: return {-z, -y, x};
    case 47: return {-z, -y, -x};
  }
  assert("unexpected transformation mode");
  return p;
}

point_t point_with_max_score(const map<point_t, int>& score) {
  set<point_t> max_s;
  int m = -1;
  for (const auto& [p, count] : score) {
    if (count > m) {
      m = count;
      max_s.clear();
      max_s.insert(p);
    } else if (count == m) max_s.insert(p);
  }
  if (max_s.size() > 1) 
    cerr << "max_s.size() != 1 (" << max_s.size() << ')' << endl;
  return *rbegin(max_s);
}


map<point_t, point_t> find_mappings(const vector<scanner_t>& scanners, 
    const int to_scanner, const int from_scanner) {
  auto o = scanners[to_scanner].overlapping_dist(scanners[from_scanner]);
  if (o.empty()) return {};

  set<point_t> beacons_to, beacons_from;
  map<point_t, map<point_t, int>> scores;
  for (auto [d, e1, e2] : o) {
    auto [i1, j1] = e1;
    auto [i2, j2] = e2;
    auto p1 = scanners[to_scanner].points[i1];
    auto p2 = scanners[to_scanner].points[j1];
    beacons_to.insert(p1);
    beacons_to.insert(p2);
    auto q1 = scanners[from_scanner].points[i2];
    auto q2 = scanners[from_scanner].points[j2];
    beacons_from.insert(q1);
    beacons_from.insert(q2);

    scores[p1][q1]++;
    scores[p1][q2]++;
    scores[p2][q1]++;
    scores[p2][q2]++;

    scores[q1][p1]++;
    scores[q1][p2]++;
    scores[q2][p1]++;
    scores[q2][p2]++;
  }
  if (beacons_to.size() < 3) return {};

  map<point_t, point_t> mapping;
  for (auto p : beacons_to) {
    auto [x, y, z] = p;
    auto match = point_with_max_score(scores[p]); 
    auto [xx, yy, zz] = match;
    mapping[p] = match;
  }
  return mapping;
}

vector<int> path_to_scanner0(const vector<space_t>& spaces, int from_scanner) {
  queue<pair<int, vector<int>>> q;
  for (int i = 0; i < spaces.size(); i++) 
    if (spaces[i].from == from_scanner)
      q.push({i, {}});
  unordered_set<int> visited_index;
  while (!q.empty()) {
    auto [index, parents] = q.front(); q.pop();
    parents.push_back(index);
    int to = spaces[index].to;
    if (to == 0) 
      return parents;
    for (int i = 0; i < spaces.size(); i++) {
      if (spaces[i].from == to && !visited_index.count(i)) {
        q.push({i, parents});
        visited_index.insert(index);
      }
    }
  }
  return {};
}

point_t to_scanner0_from_scanner_k(
    const vector<space_t>& spaces, 
    path_t& paths_to_0, 
    int k, 
    const point_t& p
) {
  auto path = paths_to_0[k];
  auto pos = p;
  for (int i = 0; i < path.size(); i++) {
    auto space = spaces[path[i]];
    pos = sub(space.scanner_pos, transform(pos, space.mode));
  }
  return pos;
}

point_t scanner_k_to_scanner0(
    const vector<space_t>& spaces, 
    path_t& paths_to_0, 
    int k
) {
  auto path = paths_to_0[k];
  auto pos = spaces[path[0]].scanner_pos;
  for (int i = 1; i < path.size(); i++) {
    auto space = spaces[path[i]];
    pos = sub(space.scanner_pos, transform(pos, space.mode));
  }
}

int main() {
  string line;
  getline(cin, line);
  vector<scanner_t> scanners;
  vector<point_t> points;
  while (getline(cin, line)) {
    if (line == "") continue;
    if (line.substr(0, 3) == "---") {
      scanner_t scanner;
      scanner.points = points;
      scanner.calc_dist();
      scanners.push_back(scanner);
      points.clear();
      continue;
    }
    replace(begin(line), end(line), ',', ' ');
    istringstream iss(line);
    int x, y, z; iss >> x >> y >> z;
    points.push_back({x, y, z});
  }
  scanner_t last_scanner;
  last_scanner.points = points;
  last_scanner.calc_dist();
  scanners.push_back(last_scanner);

  vector<space_t> spaces;

  for (int to_scanner = 0; to_scanner < scanners.size(); to_scanner++) {
    for (int from_scanner = 0; from_scanner < scanners.size(); from_scanner++) {
      if (from_scanner == to_scanner) continue;

      auto mappings = find_mappings(scanners, to_scanner, from_scanner);
      if (mappings.empty()) continue;

      for (int mode = 0; mode < 48; mode++) {
        auto& [a_point, a_mapping] = *mappings.begin();
        auto delta = transform(a_mapping, mode);
        auto scanner_pos = add(a_point, delta);

        bool invalid_transform = false;
        for (auto& [beacon_p, mapping] : mappings) {
          auto t_delta = transform(mapping, mode);
          auto beacon_pp = sub(scanner_pos, t_delta);
          if (!equal(beacon_pp, beacon_p)) {
            invalid_transform = true;
            break;
          }
        }
        if (!invalid_transform) {
          cout << "found a mapping from scanner " << from_scanner 
            << " to scanner " << to_scanner << '\n';
          space_t space;
          space.to = to_scanner;
          space.from = from_scanner;
          space.mode = mode;
          space.scanner_pos = scanner_pos;
          spaces.push_back(space);
          break;
        }
      }
    }
  }

  cout << endl << "calculating paths" << endl;
  unordered_map<int, vector<int>> paths_to_0;
  for (int k = 1; k <= scanners.size(); k++)
    paths_to_0[k] = path_to_scanner0(spaces, k);


  set<point_t> beacons;
  for (auto point : scanners[0].points) beacons.insert(point);

  cout << "transforming points" << endl;
  for (int scanner = 1; scanner < scanners.size(); scanner++) {
    for (auto point : scanners[scanner].points) {
      auto p = to_scanner0_from_scanner_k(spaces, paths_to_0, scanner, point);
      beacons.insert(p);
    }
  }

  // part 1
  cout << beacons.size() << endl;

  // part 2
  vector<point_t> scanner_pos{{0, 0, 0}};
  for (int k = 1; k < scanners.size(); k++) {
    auto path = paths_to_0[k];
    if (path.empty()) {
      cerr << "No path to scanner " << k << endl;
      exit(1);
    }

    auto s0 = scanner_k_to_scanner0(spaces, paths_to_0, k);
    cout << "scanner pos rel to scanner 0: " << to_str(s0) << endl << endl;
    scanner_pos.push_back(s0);
  }

  uint max_manhattan_dist = 0;
  for (int i = 0; i < scanner_pos.size(); i++) {
    for (int j = 0; j < scanner_pos.size(); j++) {
      uint d = manhattan_dist(scanner_pos[i], scanner_pos[j]);
      max_manhattan_dist = max(max_manhattan_dist, d);
    }
  }
  cout << max_manhattan_dist << endl;

  return 0;
}

