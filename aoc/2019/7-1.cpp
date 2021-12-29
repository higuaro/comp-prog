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

  vector<int> phase_settings{0, 1, 2, 3, 4};

  int thrusters = -1;
  do {
    int input_signal = 0;
    for (int amp = 0; amp < 5; amp++) {
      bool read_phase_setting = true;

      vector<int> mem(rom);
      for (size_t ip = 0; ip < mem.size(); ) {
        int inst = mem[ip];
        int opcode = mem[ip] % 100;
        int mode;
        bool halt = false;
        switch (opcode) {
          case 1:
          case 2: {
              mode = (inst / 100) % 10;
              int op1 = mode ? mem[ip + 1] : mem[mem[ip + 1]];
              mode = (inst / 1000) % 10;
              int op2 = mode ? mem[ip + 2] : mem[mem[ip + 2]];
              mem[mem[ip + 3]] = (opcode == 1 ? op1 + op2 : op1 * op2);
              ip += 4;
            }
            break;
          case 3:
          case 4: {
              int add = mem[ip + 1];
              if (opcode == 3) {
                mem[add] = read_phase_setting
                  ? phase_settings[amp]
                  : input_signal;
                read_phase_setting = false;
              } else {
                input_signal = mem[add];
                if (amp == 4 && input_signal > thrusters) {
                  thrusters = input_signal;
                }
              }
              ip += 2;
            }
            break;
          case 5:
          case 6: {
              mode = (inst / 100) % 10;
              int op1 = mode ? mem[ip + 1] : mem[mem[ip + 1]];
              mode = (inst / 1000) % 10;
              int op2 = mode ? mem[ip + 2] : mem[mem[ip + 2]];

              ip = opcode == 5
                  ? (op1 ? op2 : ip + 3)
                  : (!op1 ? op2 : ip + 3);
            }
            break;
          case 7:
          case 8: {
              mode = (inst / 100) % 10;
              int op1 = mode ? mem[ip + 1] : mem[mem[ip + 1]];
              mode = (inst / 1000) % 10;
              int op2 = mode ? mem[ip + 2] : mem[mem[ip + 2]];
              mem[mem[ip + 3]] = opcode == 7
                ? (op1 < op2 ? 1 : 0)
                : (op1 == op2 ? 1 : 0);
              ip += 4;
            }
            break;
          case 99: halt = true; break;
          default:
            cerr << "unexpected opcode: " << opcode
              << ", instruction: " << inst << endl;
            return 1;
        }
        if (halt) break;
      }
    }
  } while (next_permutation(begin(phase_settings), end(phase_settings)));
  cout << "thrusters = " << thrusters << endl;
  return 0;
}
