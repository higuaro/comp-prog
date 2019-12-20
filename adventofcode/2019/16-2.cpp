// compile with:
// g++ --std=c++17 16-2.cpp -o 16-2 -ltbb
//
// requires intel's thread build blocks library

#include <bits/stdc++.h>
#include <execution>

using namespace std;

int ipow(const int n, const size_t k) {
  int r = 1;
  for (size_t i = 0; i < k; i++) r *= n;
  return r;
}

int main() {
  string line;
  getline(cin, line, '\n');
  vector<int> input;
  for (auto d : line) input.push_back(d - '0');

  vector<int> seq;

  const size_t K = 1e4;
  for (size_t k = 0; k < K; k++)
    seq.insert(end(seq), begin(input), end(input));

  int size = seq.size();

  int offset = 0;
  for (int k = 6; k >= 0; k--)
    offset += seq[6 - k] * ipow(10, k);
  cerr << "offset: " << offset << endl;

  array<int, 4> pattern{0, 1, 0, -1};

  vector<int> sums(size, 0);
  vector<int> output(size, 0);

  vector<int> digit_indexes(size);
  iota(begin(digit_indexes), end(digit_indexes), 0);

  const int phases = 100;
  for (int phase = 1; phase <= phases; phase++) {
    partial_sum(begin(seq), end(seq), begin(sums));

    cerr << "phase " << phase << endl;
    for_each(
        execution::par_unseq,
        begin(digit_indexes),
        end(digit_indexes),
        [&](auto&& digit_index) {
          int sum = 0;
          int seg_size = digit_index + 1;
          for (int seg_start = 0, seg_end = max(seg_size - 1, 1); ; ) {
            int pat = pattern[((seg_start + 1) / seg_size) % 4];
            if (pat) {
               int s = seg_end ? sums[seg_end - 1] : sums[0];
               s -= seg_start ? sums[seg_start - 1] : 0;
               sum += pat * s;
            }
            seg_start = seg_end;
            seg_end = min(seg_start + seg_size, size);
            if (seg_start >= size) break;
          }
          output[digit_index] = abs(sum % 10);
        });
    seq = output;
  }

  for (int i = 0; i < 8; i++)
    cout << ((offset + i) < size ? seq[offset + i] : 0);
  cout << endl;
}
