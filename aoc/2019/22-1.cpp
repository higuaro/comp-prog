#include <bits/stdc++.h>
using namespace std;
enum technique_t { NEW, CUT, INC };
typedef pair<technique_t, int> shuffle_t;
shuffle_t parse_shuffle(const string& line) {
  istringstream iss(line);
  char c = line[0];
  if (c == 'c') {
    string token; iss >> token;
    int n; iss >> n;
    return {CUT, n};
  }
  string token;
  iss >> token; // deal
  iss >> token; // with | into
  if (token == "with") {
    // increment
    iss >> token;
    int n; iss >> n;
    return {INC, n};
  }
  return {NEW, 0};
}
int main() {
  ifstream fis("22.in");
  vector<shuffle_t> shuffles;
  string line;
  while (getline(fis, line, '\n')) {
    shuffles.push_back(parse_shuffle(line));
  }
  const int N = 9;
  //const int N = 10007;
  array<int, N> deck;
  iota(begin(deck), end(deck), 0);
  for (auto [t, n] : shuffles) {
    for (int i = 0; i < N; i++) cout << deck[i] << ' '; cout << endl;
    switch (t) {
      case NEW: {
          array<int, N> copy;
          reverse_copy(begin(deck), end(deck), begin(copy));
          deck = copy;
        }
        break;
      case CUT:
        rotate(begin(deck), begin(deck) + (n < 0 ? N + n : n), end(deck));
        break;
      case INC: {
          int i = 0;
          array<int, N> copy;
          for (int k = 0; k < N; k++) {
cerr << "i_o = " << i << endl;
            copy[i] = deck[k];
cerr << "i + n = " << (i + n) << endl;
cerr << "i + n mod 9 = " << ((i + n) % N) << endl;
            i = (i + n) % N;
cerr << "i_f = " << i << endl;
          }
          deck = copy;
        }
        break;
    }
  }
  for (int i = 0; i < N; i++) cout << deck[i] << ' '; cout << endl;
  return 0;
}
