#include <bits/stdc++.h>
using namespace std;
const int oo = numeric_limits<int>::max();
string bits; 
uint64_t to_int(const string& s) {
  uint64_t r = 0;
  uint64_t b = 1;
  for (int i = s.size() - 1; i >= 0; i--, b *= 2)
    r += static_cast<uint64_t>(s[i] - '0') * b;
  return r;
}
string hex_to_bin(const char c) {
  switch (c) {
    case '0': return "0000";
    case '1': return "0001";
    case '2': return "0010";
    case '3': return "0011";
    case '4': return "0100";
    case '5': return "0101";
    case '6': return "0110";
    case '7': return "0111";
    case '8': return "1000";
    case '9': return "1001";
    case 'A': return "1010";
    case 'B': return "1011";
    case 'C': return "1100";
    case 'D': return "1101";
    case 'E': return "1110";
    case 'F': return "1111";
  }
  return "";
}
uint64_t parse_literal(int& i) {
  string literal;
  bool keep_reading = true;
  while (keep_reading) {
    string group = bits.substr(i, 5);
    i += 5;
    keep_reading = group[0] == '1';
    literal += group.substr(1);
  }
  return to_int(literal);
}
uint64_t evaluate(int oper, const vector<uint64_t>& operands) {
  switch (oper) {
    case 0: 
      return accumulate(begin(operands), end(operands), 0ULL); 
    case 1: 
      return accumulate(begin(operands), end(operands), 1ULL, multiplies<uint64_t>());
    case 2: 
      return *min_element(begin(operands), end(operands)); 
    case 3:
      return *max_element(begin(operands), end(operands)); 
    case 5:
      return operands[0] > operands[1] ? 1 : 0;
    case 6:
      return operands[0] < operands[1] ? 1 : 0;
    case 7:
      return operands[0] == operands[1] ? 1 : 0;
  }
  return 0;
}
uint64_t parse_packet(int& i) {
  i += 3; // version

  int id = to_int(bits.substr(i, 3));
  i += 3;

  if (id == 4) {
    uint64_t literal = parse_literal(i);
    cout << "literal: " << literal << endl;
    return literal;
  } else {
    int operator_ = id;
    vector<uint64_t> operands;

    int length_type_id = bits[i++];
    if (length_type_id == '0') {
      int num_bits = to_int(bits.substr(i, 15));
      i += 15;
      int end = i + num_bits;
      while (i < end)
        operands.push_back(parse_packet(i));
    } else {
      int num_subpackets = to_int(bits.substr(i, 11));
      i += 11;

      for (int k = 0; k < num_subpackets; k++)
        operands.push_back(parse_packet(i));
    }

    return evaluate(operator_, operands);
  }
}
int main() {
  string line; cin >> line;
  for (auto c : line) bits += hex_to_bin(c);
  int i = 0;
  cout << parse_packet(i) << endl;
  return 0;
}
