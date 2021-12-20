#include <bits/stdc++.h>
using namespace std;
vector<string> parse_number(const string& n) {
  vector<string> r;
  string d = "";
  for (char c : n) {
    if (isdigit(c)) 
      d += c;
    else {
      if (d != "") {
        r.push_back(d);
        d = "";
      }
      if (c != ',')
        r.push_back(string(1, c));
    }
  }
  return r;
}

bool is_numeric(const string& s) {
  for (char c : s) 
    if (!isdigit(c)) return false;
  return true;
}

string to_str(const vector<string>& l) {
  string s, prev;
  for (auto ss : l) {
    bool use_sep = (is_numeric(prev) && is_numeric(ss)) ||
        (prev == "]" && ss == "[") ||
        (is_numeric(prev) && ss == "[") && prev != "";
    string sep = use_sep ? "," : "";
    s += sep + ss;
    prev = ss;
  }
  return s;
}

void reduce(vector<string>& n) {
  int level = 0;
  for (int i = 0; i < n.size(); i++) {
    auto s = n[i];
    if (s == "[") level++;
    if (s == "]") level--;
    
    if (level > 4 && 
        n[i - 1] == "[" 
        && is_numeric(s) && is_numeric(n[i + 1])
        && n[i + 2] == "]") {
      int v1 = stoi(s);
      int v2 = stoi(n[i + 1]);
      n.erase(begin(n) + i, begin(n) + i + 3);
      n[i - 1] = "0";
      for (int j = i - 2; j >= 0; j--)
        if (is_numeric(n[j])) {
          int k = stoi(n[j]);
          n[j] = to_string(k + v1);
          break;
        }
      for (int j = i; j < n.size(); j++) 
        if (is_numeric(n[j])) {
          int k = stoi(n[j]);
          n[j] = to_string(k + v2);
          break;
        }
      cout << "-> " << to_str(n) << '\n';
      reduce(n);
      return;
    }

    if (is_numeric(s) && stoi(s) > 9) {
      n[i] = "[";
      int k = stoi(s);
      string v1 = to_string(k / 2);
      string v2 = to_string((k + 1) / 2);
      n.insert(begin(n) + i + 1, {v1, v2, "]"});
      cout << "-> " << to_str(n) << '\n';
      reduce(n);
      return;
    }
  }
}

int main() {
  string line;
  while (cin >> line) {
    cout << line << '\n';
    auto n = parse_number(line);
    cout << to_str(n) << endl;
    reduce(n);
    cout << to_str(n) << endl;
  }
  return 0;
}
