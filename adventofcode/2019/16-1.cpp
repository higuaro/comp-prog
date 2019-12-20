#include <bits/stdc++.h>
using namespace std;
int main() {
  string line;
  getline(cin, line, '\n');
  vector<int> seq;
  for (auto d : line) seq.push_back(d - '0');

  int size = seq.size();
  array<int, 4> pattern{0, 1, 0, -1};
  const int phases = 1;

  vector<vector<int>> patterns(size, vector<int>(size, 0));
  for (int p = 0; p < size; p++)
    for (int i = 0; i < size; i++)
      patterns[p][i] = pattern[((i + 1) / (p + 1)) % 4];

  vector<int> output(seq.size(), 0);

  for (int phase = 1; phase <= phases; phase++) {
    int size = seq.size();
    for (int d = 0; d < size; d++) {
      auto& pat = patterns[d];
      int sum = 0;
      for (int i = 0; i < size; i++)
        sum += seq[i] * pat[i];
      output[d] = abs(sum % 10);
    }
    seq = output;
  }

  for (auto d : seq) cout << d; cout << endl;
}
