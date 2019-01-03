#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
template<typename T, size_t N, size_t M>
using table = array<array<T, N>, M>;
struct rect {
  int l, t, w, h;
  rect(int l, int t, int w, int h) : l(l), t(t), w(w), h(h) {}
  rect(const array<int, 4>& a) : l(a[0]), t(a[1]), w(a[2]), h(a[3]) {}
};
ostream& operator<<(ostream& oss, const rect& r) {
  return oss << '[' << r.l << ',' << r.t << ',' << r.w << ',' << r.h << ']';
}
rect parse(const string& line) {
  size_t at = 0;
  ostringstream oss;
  array<int, 4> coords;
  size_t coord_index = 0;
  bool empty = true;
  for (; at < line.size(); at++)
    if (line[at] == '@') break;
  for (size_t i = at + 2; i < line.size(); i++) {
    char c = line[i];
    if (isdigit(c)) {
      oss << c;
      empty = false;
    } else if (!empty) {
      coords[coord_index++] = stoi(oss.str());
      empty = true;
      oss.str("");
    }
  }
  coords[coord_index] = stoi(oss.str());
  return rect{coords};
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  const int N = 1000;
  table<int, N, N> fabric {0};

  vector<string> lines;
  string line;
  while (getline(cin, line, '\n'))
    lines.push_back(line);

  vector<rect> rects;
  for (auto line : lines)
    rects.push_back(parse(line));

  for (auto r : rects)
    for (int i = r.t; i < r.t + r.h; i++)
      for (int j = r.l; j < r.l + r.w; j++)
        fabric[i][j]++;

  int claims = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (fabric[i][j] > 1) claims++;

  cout << claims << std::endl;
  return 0;
}
