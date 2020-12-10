#include <bits/stdc++.h>
using namespace std;
int main() {
  enum oper_t {acc, jmp, nop};
  vector<pair<oper_t, int>> boot;
  string line;
  while (getline(cin, line, '\n')) {
    istringstream iss(line);
    string token; iss >> token;
    oper_t op = token == "nop" ? nop : (token == "jmp" ? jmp : acc);
    iss >> token;
    boot.emplace_back(op, stoi(token));
  }
  int accum = 0;
  int ip = 0;
  vector<int> count(boot.size(), 0);
  while (!count[ip]) {
    auto [op, operand] = boot[ip];
    count[ip]++;
    switch (op) {
      case jmp: ip += operand;    break;
      case acc: accum += operand; // fallthrough
      case nop: ip++;             break;
    }
  }
  cout << "accum = " << accum << endl;
  return 0;
}
