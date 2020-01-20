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
  // const int N = 10;
  const int N = 10007;
  array<int, N> deck;
  iota(begin(deck), end(deck), 0);
  for (auto [t, n] : shuffles) {
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
            copy[i] = deck[k];
            i = (i + n) % N;
          }
          deck = copy;
        }
        break;
    }
  }
  for (int i = 0; i < N; i++) {
    if (deck[i] == 2019) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
