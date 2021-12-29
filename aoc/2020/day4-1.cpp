#include <bits/stdc++.h>
using namespace std;
bool is_valid(const vector<string>& fields) {
  set<string> found;
  for (auto& field : fields) {
    ostringstream oss;
    for (char c : field) {
      if (c == ':') break;
      oss << c;
    }
    found.insert(oss.str());
  }
  return found.size() == 8 || (found.size() == 7 && !found.count("cid"));
}
int main() {
  vector<string> lines; string line;
  while (getline(cin, line, '\n'))
    lines.push_back(line);

  vector<string> fields;
  int valid = 0;
  for (auto& line : lines) {
    if (line.empty()) {
      if (is_valid(fields)) valid++;
      fields.clear();
    } else {
      istringstream ss(line);
      string field;
      while (ss >> field)
        fields.push_back(field);
    }
  }
  if (is_valid(fields)) valid++;
  cout << valid << endl;
  return 0;
}
