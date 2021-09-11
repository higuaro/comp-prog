#include <bits/stdc++.h>
using namespace std;
int main() {
  char dna[] = {'A', 'C', 'T', 'G'};
  int k = 0;
  cout << 5000 << ' ';
  for (int i = 0; i < 5000; i++) {
    cout << dna[k++];
    k %= 4;
  }
  cout << endl;
  return 0;
}
