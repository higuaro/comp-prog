#include <bits/stdc++.h>
using namespace std;
size_t parse_address(const string& s) {
  size_t i = s.find("[");
  size_t j = s.find("]");
  return stoi(s.substr(i + 1, j - i - 1));
}
string to_bin(unsigned int n) {
  string s;
  while (n) {
    char d = static_cast<char>((n % 2) + '0');
    s += d;
    n /= 2;
  }
  reverse(begin(s), end(s));
  return s;
}
uint64_t from_bin(const string& n) {
  int k = n.size();
  uint64_t res = 0ULL;
  uint64_t pow = 1ULL;
  for (int i = 0; i < k; i++, pow *= 2ULL)
    res += static_cast<uint64_t>(n[i] - '0') * pow;
  return res;
}
vector<string> apply_mask(const string& mask, size_t address) {
  string n(to_bin(address));
  int k = n.size();
  reverse(begin(n), end(n));
  for (int i = 0; i < 36 - k; i++)
    n += '0';
  reverse(begin(n), end(n));
  for (int i = 35; i >= 0; i--) {
    if (mask[i] == '0') continue;
    n[i] = mask[i];
  }

  int x_count = count(begin(n), end(n), 'X');
  int total = pow(2, x_count);
  vector<string> addresses(total, n);
  for (int k = 0; k < total; k++) {
    string& add = addresses[k];
    int x_index = 0;
    for (int i = 0; i < 36; i++) {
      if (add[i] == 'X')
        add[i] = ((k >> x_index++) & 1) + '0';
    }
  }
  return addresses;
}
int main() {
  string line;
  string mask = "";
  unordered_map<string, uint64_t> mem;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string inst; iss >> inst;
    string _; iss >> _;
    string value; iss >> value;
    if (inst == "mask") {
      mask = value;
      continue;
    }
    size_t address = parse_address(inst);
    size_t op = stoi(value);
    for (auto add : apply_mask(mask, address))
      mem[add] = op;
  }
  uint64_t sum = 0ULL;
  for (auto [_, v] : mem) {
    if (v)
      sum += v;
  }
  cout << sum << endl;
  return 0;
}
