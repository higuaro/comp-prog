#include <bits/stdc++.h>
#include "intcode_with_network.hpp"
using namespace std;
int main() {
  ifstream program("23.in");
  auto rom = intcode::parse_rom(program);

  const int M = 50;
  vector<intcode> machines;

  for (int address = 0; address < M; address++)
    machines.push_back({rom, address});

  for (int i = 0; i < M; i++) {
    auto& m = machines[i];
    m.set_input_handler([&]() -> int64_t {
      if (m.first_read) {
        m.first_read = false;
        return m.address;
      }
      if (m.packets.empty()) {
cout << m.address << ".read.empty" << endl;
        return -1;
      }

      auto& packet = m.packets.front();
      int to_return = 0;
      switch (m.read_count) {
        case 0:
          to_return = packet.first;
cout << m.address << ".read.pkg.x = " << to_return << endl;
          break;
        case 1:
          to_return = packet.second;
cout << m.address << ".read.pkg.y = " << to_return << endl;
          m.packets.pop();
          break;
      }
      m.read_count = (m.read_count + 1) % 2;
      return to_return;
    });
    m.set_output_handler([&](int64_t v) {
      switch (m.write_count) {
        case 0: m.send_to = v; break;
        case 1: m.x = v; break;
        case 2:
          m.y = v;
cout << m.address << ".send to(" << m.send_to << ").pkg(" << m.x << ',' << m.y << ')' << endl;
          if (m.send_to == 255) {
            cout << "Y for address 255 = " << m.y << endl;
            exit(0);
          }
          machines[m.send_to].packets.push({m.x, m.y});
        break;
      }
      m.write_count = (m.write_count + 1) % 3;
    });
  }

for (auto& m : machines) {
  cout << "D: address " << m.address << endl;
}

  bool none_halt = true;
  while (none_halt) {
    for (auto& m : machines)
      none_halt &= m.step();
  }
}

