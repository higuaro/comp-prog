#ifndef INTCODE_HPP
#define INTCODE_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <sstream>
#include <queue>

class intcode {
  const std::vector<int64_t>& rom;
  std::vector<int64_t> mem;
  std::function<int64_t()> input_handler;
  std::function<void(int64_t)> output_handler;

  bool halted;
  bool paused;
  int64_t relative_base;
  size_t ip;

public:
  int address;
  bool first_read = true;
  int read_count = 0;
  int write_count = 0;
  int64_t send_to, x, y;
  std::queue<std::pair<int64_t, int64_t>> packets;

public:
  intcode(const std::vector<int64_t>& rom, int address) : rom(rom), mem(rom),
    halted(false), paused(false), relative_base(0), ip(0), address(address),
    read_count(0), write_count(0) {
    add_empty_memory();
  }

  void set_input_handler(const std::function<int64_t()>& ih) {
    this->input_handler = ih;
  }

  void set_output_handler(const std::function<void(int64_t)>& oh) {
    this->output_handler = oh;
  }

  void reset() {
    mem = rom;
    add_empty_memory();
    ip = 0;
    halted = false;
    paused = false;
    relative_base = 0;
  }

  void pause() {
    paused = true;
  }

  void resume() {
    paused = false;
  }

  bool is_halted() const {
    return halted;
  }

  bool is_first_read() const {
    return first_read;
  }

  void run() {
    while (step());
  }

  bool step() {
// std::cerr << address << ": step, ip = " << ip << std::endl;
    if (ip < mem.size() && !paused && !halted) {
      int64_t inst = mem[ip];
      int64_t opcode = mem[ip] % 100;
      int64_t mode;
      // std::clog << "inst " << inst << " ip " << ip << std::endl;
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
              int64_t val = input_handler();
              int64_t add = read_address(mem, mode, ip + 1, relative_base);
              mem[add] = val;
            } else {
              int64_t val = read_op(mem, mode, ip + 1, relative_base);
              output_handler(val);
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
        case 99:
          halted = true;
          return false;
        default:
          std::cerr << "unexpected opcode: " << opcode << ", instruction: " << inst << std::endl;
          halted = true;
          return false;
      }
      return true;
    }
    return false;
  }

private:
  void add_empty_memory() {
    for (size_t i = 0; i < 2 * rom.size(); i++)
      mem.push_back(0);
  }

  int64_t read_op(std::vector<int64_t>& mem, int64_t mode, int64_t ip,
      int64_t relative_base) {
    switch (mode) {
      case 0:
        return mem[mem[ip]];
      case 1:
        return mem[ip];
      case 2:
        return mem[mem[ip] + relative_base];
      default:
        std::cerr << "unkwon mode " << mode << std::endl;
        exit(1);
    }
  }

  int64_t read_address(std::vector<int64_t>& mem, int64_t mode, int64_t ip, int64_t relative_base) {
    switch (mode) {
      case 0:
        return mem[ip];
      case 2:
        return mem[ip] + relative_base;
      default:
        std::cerr << "invalid mode for destination address" << mode << std::endl;
        exit(1);
    }
  }

public:
  static std::vector<int64_t> parse_rom(std::istream& in) {
    std::string line;
    getline(in, line);
    std::stringstream ss(line);
    std::vector<int64_t> rom;
    int64_t tmp;
    while (ss >> tmp) {
      rom.push_back(tmp);
      ss.ignore(1);
    }
    return rom;
  }
};

#endif
