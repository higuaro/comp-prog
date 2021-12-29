#include <bits/stdc++.h>
using namespace std;
enum step_type { operation, number };
struct step_t {
  step_type type;
  union { char operation; uint64_t number; };
};
inline step_t to_num(const string& n) {
  step_t s; s.type = number;
  s.number = stoi(n);
  return s;
}
inline step_t to_oper(char o) {
  step_t s; s.type = operation;
  s.operation = o;
  return s;
}
inline int prec(const char op) {
  return op == '+' ? 2 : (op == '*' ? 1 : 0);
}
void print_rpn(const vector<step_t>& rpn) {
  for (auto s : rpn)
    if (s.type == number)
      cout << s.number << ' ';
    else 
      cout << s.operation << ' ';
  cout << endl;
}
uint64_t evaluate_rpn(const vector<step_t>& rpn) {
  stack<uint64_t> numbers;
  for (auto& token : rpn) {
    switch (token.type) {
      case operation: {
        uint64_t a = numbers.top(); numbers.pop();
        uint64_t b = numbers.top(); numbers.pop();
        numbers.push(token.operation == '+' ? a + b : a * b);
        break;
      }
      case number: { numbers.push(token.number); break; }
    }
  }
  return numbers.top();
}
vector<step_t> shunting_yard(const string& expression) {
  vector<step_t> output;
  stack<char> oper;
  string token;
  for (char c : expression) {
    if (c == ' ') continue;
    if (isdigit(c)) {
      token += c;
      continue;
    } else if (!token.empty()) {
      output.push_back(to_num(token));
      token = "";
    }
    switch (c) {
      case '(': oper.push('('); break;
      case ')':
        while (!oper.empty()) {
          char o = oper.top();
          if (o == '(') {
            oper.pop();
            break;
          }
          output.push_back(to_oper(o));
          oper.pop();
        }
        break;
      default:
        int prec_c = prec(c);
        while (!oper.empty()) {
          char o = oper.top();
          if (prec(o) > prec_c) {
            output.push_back(to_oper(o));
            oper.pop();
          } else
            break;
        }
        oper.push(c);
    }
  }
  if (!token.empty())
    output.push_back(to_num(token));
  while (!oper.empty()) {
    output.push_back(to_oper(oper.top()));
    oper.pop();
  }
  return output;
}
int main() {
  uint64_t total = 0ULL;
  string expression;
  while (getline(cin, expression, '\n')) {
    auto rpn = shunting_yard(expression);
    //print_rpn(rpn);
    total += evaluate_rpn(rpn);
  }
  cout << total << endl;
  return 0;
}
