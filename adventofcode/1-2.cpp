#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tmp;
  vector<int> freqs;
  std::copy(std::istream_iterator<int>(std::cin), 
            std::istream_iterator<int>(), 
            std::back_inserter(freqs));
  int cur_freq = 0;
  std::set<int> freqs_found{cur_freq};
  while (true) {
    for (auto f : freqs) {
      cur_freq += f;
      if (freqs_found.count(cur_freq)) {
        cout << cur_freq << '\n';
        return 0;
      } else {
        freqs_found.insert(cur_freq);
      }
    }
  }
  return 0;
}
