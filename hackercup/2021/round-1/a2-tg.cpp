#include <bits/stdc++.h>
using namespace std;
string tc(uniform_int_distribution<int>& dist, mt19937& gen, const int N) {
  const array<char, 3> ALPH{'X', 'F', 'O'};
  ostringstream oss;
  for (int i = 0; i < N; i++) 
    oss << ALPH[dist(gen)];
  return oss.str();
}
int main() {
  random_device dev;
  mt19937 gen(dev());
  uniform_int_distribution<int> dist(0, 2);
  cout << 75 << '\n';
  // first 4 have 800000 chars filled with random
  for (int k = 0; k < 4; k++) 
    cout << static_cast<int>(8e5) << '\n' << tc(dist, gen, 8e5) << '\n';
  for (int k = 0; k < 71; k++)
    cout << 11266 << '\n' << tc(dist, gen, 11266) << '\n';
  return 0;
}
