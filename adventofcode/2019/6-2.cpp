#include <bits/stdc++.h>
using namespace std;
vector<string> find_parents(unordered_map<string, string>& parents,
    const string& child) {
  vector<string> p;
  string node(child);
  while (parents.count(node))
    p.push_back(node = parents[node]);
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, string> parents;
  string line;

  while (getline(cin, line, '\n')) {
    istringstream ss(line);
    string a; getline(ss, a, ')');
    string b; getline(ss, b, '\n');

    parents[b] = a;
  }

  auto parents_you = find_parents(parents, "YOU");
  auto parents_san = find_parents(parents, "SAN");

  for (size_t y = 0; y < parents_you.size(); y++)
    for (size_t s = 0; s < parents_san.size(); s++)
      if (parents_you[y] == parents_san[s]) {
        cout << y + s << endl;
        return 0;
      }

  return 0;
}
