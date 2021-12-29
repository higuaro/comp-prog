#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  getline(cin, line, '\n');
  stringstream ss(line);
  vector<int> rom;
  int tmp;
  while (ss >> tmp) {
    rom.push_back(tmp);
    ss.ignore(1);
  }

  for (int noun = 0; noun <= 99; noun++) {
    for (int verb = 0; verb <= 99; verb++) {
      vector<int> mem(rom);
      mem[1] = noun; mem[2] = verb;
      for (size_t ip = 0; ip < mem.size(); ip += 4) {
        int opcode = mem[ip];
        if (opcode == 99) break;
        int op1 = mem[mem[ip + 1]];
        int op2 = mem[mem[ip + 2]];
        mem[mem[ip + 3]] = (opcode == 1 ? op1 + op2 : op1 * op2);
      }
      if (mem[0] == 19690720) {
        cout << (100 * noun + verb) << endl;
        return 0;
      }
    }
  }
  return 0;
}
