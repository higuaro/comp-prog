#include <bits/stdc++.h>
using namespace std;
uint64_t apply_operation(uint64_t accum, char operation, uint64_t operand) {
  switch (operation) {
    case 0:   return operand;
    case '+': return accum + operand;
    case '*': return accum * operand;
  }
  return 0ULL;
}
int main() {
  uint64_t total = 0ULL;
  string formula;
  while (getline(cin, formula, '\n')) {
    stack<pair<uint64_t, char>> saved;
    uint64_t result = 0;
    char operation = 0;

    istringstream iss(formula);
    string token;
    while (iss >> token) {
      char first = token[0];
      if (first == '+' || first == '*') {
        operation = first;
        continue;
      }

      int closed = 0;
      if (first == '(') {
        while (token[0] == '(') {
          saved.push({result, operation});
          token = token.substr(1);
          operation = 0;
        }
      } else if (token.back() == ')') {
        while (token[token.size() - 1] == ')') {
          token = token.substr(0, token.size() - 1);
          closed++;
        }
      }

      uint64_t op = stoi(token);
      result = apply_operation(result, operation, op);

      while (closed--) {
        auto [prev_result, prev_operation] = saved.top(); saved.pop();
        result = apply_operation(prev_result, prev_operation, result);
      }
    }
    total += result;
  }
  cout << total << endl;
  return 0;
}
