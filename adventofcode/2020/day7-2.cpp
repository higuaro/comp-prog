#include <bits/stdc++.h>
using namespace std;

unordered_map<string, set<pair<string, int>>> g;

string read_name(istringstream& iss, const vector<string>& delim) {
  string name, token;
  while (iss >> token) {
    for (auto& d : delim)
      if (token == d)
        return name;
    if (!name.empty()) name += ' ';
    name += token;
  }
  return name;
}

int dfs(const string& node = "shiny gold") {
  int t = 0;
  for (auto& [child, count] : g[node])
    t += count * (1 + dfs(child));
  return t;
}

int main() {
  string line;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string token;
    auto bag_name = read_name(iss, {"bags"});
    while (iss >> token) {
      if (token == "contain") continue;
      if (token == "no") {
        g[bag_name] = {};
        break;
      }
      int count = stoi(token);
      auto child_bag_name = read_name(iss, {"bag,", "bags,", "bag.", "bags."});
      g[bag_name].insert({child_bag_name, count});
    }
  }
  cout << dfs() << endl;
  return 0;
}
