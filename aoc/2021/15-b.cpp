#include <bits/stdc++.h>
using namespace std;
const int oo = numeric_limits<int>::max();
const int o[] = {-1, 0, 1, 0, -1};

typedef unordered_map<int, vector<pair<int, int>>> adj_t;

int solve(const vector<string>& board, const int size) {
  adj_t adj;
  for (int node = 0; node < size * size; node++) {
    int i = node / size;
    int j = node % size;
    for (int k = 0; k < 4; k++) {
      int ii = i + o[k];
      int jj = j + o[k + 1];
      if (0 <= ii && ii < size && 0 <= jj && jj < size) {
        int child = ii * size + jj;
        int risk = board[ii][jj] - '0';
        adj[node].push_back({child, risk});
      }
    }
  }

  vector<int> distance(size * size, oo);
  vector<bool> processed(size * size, false);
  distance[0] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    int a = q.top().second; q.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (auto u : adj[a]) {
      int b = u.first, w = u.second;
      if (distance[a] + w < distance[b]) {
        distance[b] = distance[a] + w;
        q.push({-distance[b], b});
      }
    }
  }
  return distance[size * size - 1];
}

string repeat(const string& s, int n) {
  string r;
  for (int i = 0; i < n; i++) r += s;
  return r;
}

int main() {
  vector<string> lines;
  string line;
  while (cin >> line)
    lines.push_back(line);
  int size = lines.size();

  vector<string> new_lines;
  for (auto l : lines) {
    string new_line = repeat(l, 5);
    for (int i = 0; i < new_line.size(); i++) {
      int tile_index = i / l.size();
      char c = new_line[i] + tile_index;
      new_line[i] = c > '9' ? '0' + (c - '9') : c;
    }
    new_lines.push_back(new_line);
  }

  for (int k = 0; k < 4; k++)
    for (int i = 0; i < size; i++)
      new_lines.push_back(new_lines[i]);
  for (int i = 0; i < new_lines.size(); i++) {
    for (int j = 0; j < new_lines[i].size(); j++) {
      int tile_index = i / size;
      char c = new_lines[i][j] + tile_index;
      new_lines[i][j] = c > '9' ? '0' + (c - '9') : c;
    }
  }

  size *= 5;
for (int i = 0; i < size; i++) {
  for (int j = 0; j < size; j++) {
    cout << new_lines[i][j];
  }
  cout << endl;
}
  cout << solve(new_lines, size) << endl;
  return 0;
}
