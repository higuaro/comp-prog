#include <bits/stdc++.h>
using namespace std;

int64_t read_op(vector<int64_t>& mem, int64_t mode, int64_t ip, int64_t relative_base) {
  switch (mode) { 
    case 0:
      return mem[mem[ip]];
    case 1:
      return mem[ip];
    case 2:
      return mem[mem[ip] + relative_base];
    default:
      cerr << "unkwon mode " << mode << endl;
      exit(1);
  }
}

int64_t read_address(vector<int64_t>& mem, int64_t mode, int64_t ip, int64_t relative_base) {
  switch (mode) { 
    case 0:
      return mem[ip];
    case 2:
      return mem[ip] + relative_base;
    default:
      cerr << "invalid mode for destination address" << mode << endl;
      exit(1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fis("11.in");
  cin.tie(nullptr);

  string line;
  getline(fis, line, '\n');
  stringstream ss(line);
  vector<int64_t> mem;
  int64_t tmp;
  while (ss >> tmp) {
    mem.push_back(tmp);
    ss.ignore(1);
  }

  map<pair<int, int>, int> board;
  int offset_r[] = { -1, 0, 1, 0 };
  int offset_c[] = {  0, 1, 0, -1 };
  int cur_row = 0, cur_col = 0;
  int dir = 0;
  board[make_pair(cur_row, cur_col)] = 0;
  int output_type = 0;
  set<pair<int, int>> painted;

  for (size_t i = 0, size = mem.size(); i < size; i++)
    mem.push_back(0);

  int64_t relative_base = 0;
  for (size_t ip = 0; ip < mem.size(); ) {
    int64_t inst = mem[ip];
    int64_t opcode = mem[ip] % 100;
    int64_t mode;
    bool halt_program = false;
// clog << "inst " << inst << " ip " << ip << endl;
    switch (opcode) {
      case 1:
      case 2: {
          mode = (inst / 100) % 10;
          int64_t op1 = read_op(mem, mode, ip + 1, relative_base);
          mode = (inst / 1000) % 10;
          int64_t op2 = read_op(mem, mode, ip + 2, relative_base);
          mode = (inst / 10000) % 10;
          int add = read_address(mem, mode, ip + 3, relative_base);
          mem[add] = (opcode == 1 ? op1 + op2 : op1 * op2);
          ip += 4;
        }
        break;
      case 3:
      case 4: {
          mode = (inst / 100) % 10;
          if (opcode == 3) {
            int64_t val;
            auto pos = make_pair(cur_row, cur_col);
            if (board.count(pos)) {
              val = board[pos];
            } else {
              val = board[pos] = 0;
            }
            int64_t add = read_address(mem, mode, ip + 1, relative_base);
            mem[add] = val;
          } else {
            int robot_output = read_op(mem, mode, ip + 1, relative_base);
            if (output_type) {
              int offset = robot_output ? 1 : -1;
              dir = (dir + offset + 4) % 4;
              cur_row += offset_r[dir];
              cur_col += offset_c[dir];
            } else {
              auto pos = make_pair(cur_row, cur_col);
              board[pos] = robot_output;
              painted.insert(pos);
            }
            output_type = (output_type + 1) % 2;
          }
          ip += 2;
        }
        break;
      case 5:
      case 6: {
          mode = (inst / 100) % 10;
          int64_t op1 = read_op(mem, mode, ip + 1, relative_base);
          mode = (inst / 1000) % 10;
          int64_t op2 = read_op(mem, mode, ip + 2, relative_base);

          ip = opcode == 5
              ? (op1 ? op2 : ip + 3)
              : (!op1 ? op2 : ip + 3);
        }
        break;
      case 7:
      case 8: {
          mode = (inst / 100) % 10;
          int64_t op1 = read_op(mem, mode, ip + 1, relative_base);
          mode = (inst / 1000) % 10;
          int64_t op2 = read_op(mem, mode, ip + 2, relative_base);
          mode = (inst / 10000) % 10;
          int add = read_address(mem, mode, ip + 3, relative_base);
          mem[add] = opcode == 7
            ? (op1 < op2 ? 1 : 0)
            : (op1 == op2 ? 1 : 0);
          ip += 4;
        }
        break;
      case 9: {
          mode = (inst / 100) % 10;
          int64_t offset = read_op(mem, mode, ip + 1, relative_base);
          relative_base += offset;
          ip += 2;
        }
        break;
      case 99: halt_program = true; break;
      default:
        cerr << "unexpected opcode: " << opcode
          << ", instruction: " << inst << endl;
        return 1;
    }
    if (halt_program) break;
  }

  cout << painted.size() << endl;
  return 0;
}
