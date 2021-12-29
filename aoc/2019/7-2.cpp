#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  getline(cin, line, '\n');
  stringstream ss(line);
  vector<int64_t> rom;
  int tmp;
  while (ss >> tmp) {
    rom.push_back(tmp);
    ss.ignore(1);
  }

  vector<int> phase_settings{5, 6, 7, 8, 9};

  int64_t max_thrusters = 0;
  do {
    int64_t input_signal = 0;
    int64_t thrusters = 0;

    vector<vector<int64_t>> programs(5, rom);

    array<bool, 5> read_phase_setting;
    read_phase_setting.fill(true);
    array<bool, 5> halted;
    halted.fill(false);

    vector<int> ips(5, 0);

    bool halt_feedback_loop = false;
    bool jump_next_amp = false;
    for (int amp = 0;;) {
      for (;;) {
        if (halted[amp] || jump_next_amp) {
          amp = (amp + 1) % 5;
          jump_next_amp = false;
          continue;
        }

        vector<int64_t>& program = programs[amp];

        int ip = ips[amp];
        int inst = program[ip];
        int opcode = program[ip] % 100;
        int mode;

        switch (opcode) {
          case 1:
          case 2: {
              mode = (inst / 100) % 10;
              int64_t op1 = mode ? program[ip + 1] : program[program[ip + 1]];
              mode = (inst / 1000) % 10;
              int64_t op2 = mode ? program[ip + 2] : program[program[ip + 2]];
              program[program[ip + 3]] = (opcode == 1 ? op1 + op2 : op1 * op2);
              ip += 4;
            }
            break;
          case 3:
          case 4: {
              int64_t address = program[ip + 1];
              if (opcode == 3) {
                program[address] = read_phase_setting[amp]
                  ? phase_settings[amp]
                  : input_signal;
                read_phase_setting[amp] = false;
              } else {
                input_signal = program[address];
                jump_next_amp = true;
              }
              ip += 2;
            }
            break;
          case 5:
          case 6: {
              mode = (inst / 100) % 10;
              int64_t op1 = mode ? program[ip + 1] : program[program[ip + 1]];
              mode = (inst / 1000) % 10;
              int64_t op2 = mode ? program[ip + 2] : program[program[ip + 2]];

              ip = opcode == 5
                  ? (op1 ? op2 : ip + 3)
                  : (!op1 ? op2 : ip + 3);
            }
            break;
          case 7:
          case 8: {
              mode = (inst / 100) % 10;
              int64_t op1 = mode ? program[ip + 1] : program[program[ip + 1]];
              mode = (inst / 1000) % 10;
              int64_t op2 = mode ? program[ip + 2] : program[program[ip + 2]];
              program[program[ip + 3]] = opcode == 7
                ? (op1 < op2 ? 1 : 0)
                : (op1 == op2 ? 1 : 0);
              ip += 4;
            }
            break;
          case 99:
            if (amp == 4) {
              thrusters = input_signal;
              halt_feedback_loop = true;
            }
            halted[amp] = true;
            break;
          default:
            cerr << "unexpected opcode: " << opcode
              << ", instruction: " << inst << endl;
            return 1;
        }
        ips[amp] = ip;
        if (halt_feedback_loop) break;
      }
      if (halt_feedback_loop) break;
    }

    if (thrusters > max_thrusters)
      max_thrusters = thrusters;

  } while (next_permutation(begin(phase_settings), end(phase_settings)));
  cout << "max_thrusters = " << max_thrusters << endl;
  return 0;
}
