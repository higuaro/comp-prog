#include <bits/stdc++.h>
using namespace std;
bool is_valid(const vector<string>& fields) {
  set<string> found;
  for (auto& field : fields) {
    ostringstream koss, voss;
    ostringstream* oss = &koss;
    for (char c : field) {
      if (c == ':') {
        oss = &voss;
        continue;
      }
      (*oss) << c;
    }
    string key(koss.str());
    string value(voss.str());
    if (key == "byr") {
      int y = stoi(value);
      if (y < 1920 || 2002 < y) return false;
    } else if (key == "iyr") {
      int y = stoi(value);
      if (y < 2010 || 2020 < y) return false;
    } else if (key == "eyr") {
      int y = stoi(value);
      if (y < 2020 || 2030 < y) return false;
    } else if (key == "hgt") {
      string type = value.substr(value.size() - 2);
      if (type != "cm" && type != "in") return false;
      int h = stoi(value.substr(0, value.size() - 2));
      if (type == "cm" && (h < 150 || 193 < h)) return false;
      if (type == "in" && (h < 59 || 76 < h)) return false;
    } else if (key == "hcl") {
      if (value.size() != 7) return false;
      if (value[0] != '#') return false;
      for (int i = 1; i < 7; i++) {
        char c = value[i];
        if (!('a' <= c && c <= 'f') && !('0' <= c && c <= '9')) return false;
      }
    } else if (key == "ecl") {
      set<string> c{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
      if (!c.count(value)) return false;
    } else if (key == "pid") {
      if (value.size() != 9) return false;
      for (int i = 0; i < 9; i++) {
        char d = value[i];
        if (!('0' <= d && d <= '9')) return false;
      }
    }
    found.insert(key);
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
