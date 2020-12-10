#include <bits/stdc++.h>
using namespace std;
enum oper_t {acc, jmp, nop};
typedef vector<pair<oper_t, int>> program_t;
int run(const program_t& boot) {
  int accum = 0;
  int ip = 0;
  int n = boot.size();
  vector<int> count(n, 0);
  while (ip < n && !count[ip]) {
    auto [op, arg] = boot[ip];
    count[ip]++;
    switch (op) {
      case jmp: ip += arg;    break;
      case acc: accum += arg; // fallthrough
      case nop: ip++;         break;
    }
  }
  return ip == n ? accum : -1;
}
int main() {
  vector<pair<oper_t, int>> boot;
  string line;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string token; iss >> token;
    oper_t op = token == "nop" ? nop : (token == "jmp" ? jmp : acc);
    iss >> token;
    boot.emplace_back(op, stoi(token));
  }
  int n = boot.size();
  for (int i = 0; i < n; i++) {
    auto [op, arg] = boot[i];
    if (op == acc) continue;
    oper_t op2 = op == nop ? jmp : nop;
    boot[i] = {op2, arg};
    int accum = run(boot);
    if (accum > 0) {
      cout << accum << endl;
      return 0;
    }
    boot[i] = {op, arg};
  }
  return 0;
}
