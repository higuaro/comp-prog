#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  ifstream fis("5.in");
  cin.tie(nullptr);

  string line;
  getline(fis, line, '\n');
  stringstream ss(line);
  vector<int> mem;
  int tmp;
  while (ss >> tmp) {
    mem.push_back(tmp);
    ss.ignore(1);
  }
  for (size_t ip = 0; ip < mem.size(); ) {
    int inst = mem[ip];
    int opcode = mem[ip] % 100;
    int mode;
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
            int val; cin >> val;
            mem[add] = val;
          } else
            cout << mem[add] << endl;
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
      case 99: return 0;
      default:
        cerr << "unexpected opcode: " << opcode
          << ", instruction: " << inst << endl;
        return 1;
    }
  }
  return 0;
}
