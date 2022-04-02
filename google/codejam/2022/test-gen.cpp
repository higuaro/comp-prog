#include <bits/stdc++.h>
using namespace std;

int main() {
  const int M = 1e6;
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(4, M); 

  cout << "100\n";
  for (int t = 0; t < 100; t++) {
    cout << M << '\n';
    for (int k = 0; k < M; k++)
      std::cout << dist(rng) << ' ';
    cout << '\n';
  }
  return 0;
}
