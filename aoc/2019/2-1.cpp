#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  getline(cin, line, '\n');
  stringstream ss(line);
  vector<int> mem;
  int tmp;
  while (ss >> tmp) {
    mem.push_back(tmp);
    ss.ignore(1);
  }
  mem[1] = 12; mem[2] = 2;
  for (size_t ip = 0; ip < mem.size(); ip += 4) {
    int opcode = mem[ip];
    if (opcode == 99) break;
    int op1 = mem[mem[ip + 1]];
    int op2 = mem[mem[ip + 2]];
    mem[mem[ip + 3]] = (opcode == 1 ? op1 + op2 : op1 * op2);
  }

  for (auto m : mem) cout << m << ' ';
  cout << endl;

  return 0;
}
