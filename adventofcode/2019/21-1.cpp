#include <bits/stdc++.h>
#include "intcode.hpp"
using namespace std;
int main() {
  ifstream program("21.in");
  auto rom = intcode::parse_rom(program);

  queue<char> input;
  vector<char> output;

  int script_index = 0;
  vector<string> script{
    "NOT B T",
    "NOT C J",
    "OR T J",
    "AND D J",
    "NOT A T",
    "OR T J",
    "WALK"
  };

  intcode machine{rom,
    [&]() -> int64_t {
      if (input.empty()) {
        string line = script[script_index++];
        cout << line << endl;
        for (auto c : line)
          input.push(c);
        input.push('\n');
      }
      auto c = input.front(); input.pop();
      return static_cast<int64_t>(c);
    },
    [&](int64_t v) {
      if (v > 256) {
        cout << "damage = " << v << endl;
        return;
      }
      char c = static_cast<char>(v);
      if (c == '\n') {
        string line(begin(output), end(output));
        cout << line << endl;
        output.clear();
      } else
        output.push_back(c);
    }
  };
  machine.run();
  return 0;
}
