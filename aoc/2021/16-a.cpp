#include <bits/stdc++.h>
using namespace std;
const int oo = numeric_limits<int>::max();
int to_int(const string& s) {
  int r = 0;
  for (int i = s.size() - 1, b = 1; i >= 0; i--, b *= 2)
    r += (s[i] - '0') * b;
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
pair<int, int> parse_literal(const string& bits, int i) {
  string literal;
  bool keep_reading = true;
  while (keep_reading) {
    string group = bits.substr(i, 5);
    i += 5;
    keep_reading = group[0] == '1';
    literal += group.substr(1);
  }
  return {i, to_int(literal)};
}
pair<int, int> parse_packet(const string& bits, int packet_limit = oo) {
  int version_sum = 0;
  int num_packages = 0;
  int i = 0;
  while (i < bits.size()) {
    int version = to_int(bits.substr(i, 3));

    i += 3; 
    if (i >= bits.size()) break;

    int id = to_int(bits.substr(i, 3));

    i += 3;
    if (i >= bits.size()) break;

    if (id == 4) {
      auto [ii, literal] = parse_literal(bits, i);
      cout << "literal: " << literal << endl;
      i = ii; 
    } else {
      int length_type_id = bits[i++];
      if (length_type_id == '0') {
        string total_length_in_bits = bits.substr(i, 15);

        i += 15; 
        if (i >= bits.size()) break;

        int num_bits = to_int(total_length_in_bits);
        string sub_packages = bits.substr(i, num_bits);
        auto [ii, v_sum] = parse_packet(sub_packages);
        version_sum += v_sum;
        i += ii; 
      } else {
        int num_subpackets = to_int(bits.substr(i, 11));

        i += 11; 
        if (i >= bits.size()) break;

        auto [ii, v_sum] = parse_packet(bits.substr(i), num_subpackets);
        version_sum += v_sum;
        i += ii;
      }
    }
    num_packages++;
    version_sum += version;
    if (num_packages >= packet_limit) break;
  }
  return {i, version_sum};
}
int main() {
  string line; cin >> line;
  string bits;
  for (auto c : line) bits += hex_to_bin(c);
  cout << parse_packet(bits).second << endl;
  return 0;
}
