#include <iostream>
#include <vector>
#include <variant>
#include <sstream>
using namespace std;
enum operation { inp, add, mul, div, mod, eql };
enum variable { x, y, z, w, none };
struct instruction_t {
  operation op;
  variable var;
  variant<int, variable> operand;

  string str() {
    const vector<string> s_var{"x", "y", "z", "w", ""};
    const vector<string> s_op{"inp", "add", "mul", "div", "mod", "eql"};
    ostringstream oss;
    oss << s_op[op] << ' ' << s_var[var] << ' ';
    if (!operand.index())
      oss << get<int>(operand);
    else
      oss << s_var[get<variable>(operand)];
    return oss.str();
  }
};

variable to_var(const string& v) {
  if (v == "x") return variable::x;
  else if (v == "y") return variable::y;
  else if (v == "z") return variable::z;
  else if (v == "w") return variable::w;
  return variable::none;
}

instruction_t parse_instruction(const string& line) {
  istringstream iss(line);
  string op, var; iss >> op >> var;
  if (op == "inp")
    return { operation::inp, to_var(var), variable::none };
  string s_operand; iss >> s_operand;
  variable v = to_var(s_operand);
  variant<int, variable> operand;
  if (v == variable::none)
    operand = stoi(s_operand);
  else
    operand = v;
  if (op == "add")
    return { operation::add, to_var(var), operand };
  else if (op == "mul")
    return { operation::mul, to_var(var), operand };
  else if (op == "div")
    return { operation::div, to_var(var), operand };
  else if (op == "mod")
    return { operation::mod, to_var(var), operand };
  else if (op == "eql")
    return { operation::eql, to_var(var), operand };

  cerr << "invalid instruction" << endl;
  return {};
}

vector<int> evaluate_program(const vector<instruction_t>& program, const vector<int>& input) {
  int input_index = 0;
  vector<int> vars(4, 0); // x, y, z, w;
  for (auto instruction : program) {
    if (instruction.op == operation::inp) {
      vars[instruction.var] = input[input_index++];
      continue;
    }
    int a = vars[instruction.var];
    int b;
    if (instruction.operand.index())
      b = vars[get<variable>(instruction.operand)];
    else
      b = get<int>(instruction.operand);

    switch (instruction.op) {
      case operation::add: vars[instruction.var] = a + b; break;
      case operation::mul: vars[instruction.var] = a * b; break;
      case operation::div: vars[instruction.var] = a / b; break;
      case operation::mod: vars[instruction.var] = a % b; break;
      case operation::eql: vars[instruction.var] = a == b ? 1 : 0; break;
      default:
        cout << "unexpected operation" << endl;
    }
  }
  return vars;
}

vector<int> to_digits(uint64_t n) {
  vector<int> digits;
  while (n) {
    auto d = static_cast<int>(n % 10ULL);
    digits.push_back(d);
    n /= 10;
  }
  reverse(begin(digits), end(digits));
  return digits;
}

uint64_t from_digits(const vector<int>& digits) {
  uint64_t r = 0;
  for (int digit : digits)
    r = r * 10 + digit;
  return r;
}
string digits_to_str(const vector<int>& digits) {
  ostringstream oss;
  for (auto d : digits) oss << d;
  return oss.str();
}
int main() {
  vector<instruction_t> monad;
  string line;
  while (getline(cin, line)) {
    if (line == "") continue;
    monad.push_back(parse_instruction(line));
  }

  auto digits = to_digits(99999999541462);
  auto limit = to_digits(99999999541461);
  while (digits != limit) {
    //cout << "trying: " << from_digits(digits) << endl;
    auto valid = evaluate_program(monad, digits)[variable::z] == 0;
    if (valid) {
      cout << "max_serial: " << from_digits(digits) << endl;
      return 0;
    }

    for (int i = 13; i >= 0; i--) {
      if (digits[i] > 1) {
        digits[i]--;
        break;
      } else
        digits[i] = 9;
    }
  }
  return 0;
}
