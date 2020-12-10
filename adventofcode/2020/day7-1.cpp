#include <bits/stdc++.h>
using namespace std;
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
int main() {
  unordered_map<string, set<string>> rev_g;
  string line;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string token;
    auto bag_name = read_name(iss, {"bags"});
    while (iss >> token) {
      if (token == "contain") continue;
      if (token == "no")
        break;
      auto child_bag_name = read_name(iss, {"bag,", "bags,", "bag.", "bags."});
      rev_g[child_bag_name].insert(bag_name);
    }
  }
  int containers = -1;
  stack<string> s; s.push("shiny gold");
  set<string> seen;
  while (!s.empty()) {
    auto bag = s.top(); s.pop();
    seen.insert(bag);
    for (auto& child : rev_g[bag])
      if (!seen.count(child)) {
        s.push(child);
        seen.insert(child);
      }
    containers++;
  }
  cout << containers << endl;
  return 0;
}
