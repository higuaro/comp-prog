#include <bits/stdc++.h>
using namespace std;
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
uint64_t apply_mask(const string& mask, string& n) {
  int k = n.size();
  reverse(begin(n), end(n));
  for (int i = 0; i < 36 - k; i++)
    n += '0';
  reverse(begin(n), end(n));
  for (int i = 35; i >= 0; i--) {
    if (mask[i] == 'X') continue;
    n[i] = mask[i];
  }
  reverse(begin(n), end(n));
  return from_bin(n);
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
    string op = to_bin(stoi(value));
    mem[inst] = apply_mask(mask, op);
  }
  uint64_t sum = 0ULL;
  for (auto [_, v] : mem) {
    if (v)
      sum += v;
  }
  cout << sum << endl;
  return 0;
}
