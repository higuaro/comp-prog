#include <bits/stdc++.h>
using namespace std;
int mod(int k, int n) {
  return (k % n + n) % n;
}
int main() {
  int p1 = 9 - 1;
  int p2 = 10 - 1;

  vector<int> pos(10, 0);
  iota(begin(pos), end(pos), 1);

  vector<int> die(100, 0);
  iota(begin(die), end(die), 1);

  int score1 = 0, score2 = 0;
  int i = 0;
  int rolls = 0;
  while (score1 < 1000 && score2 < 1000) {
    i = mod(i + 3, 100);
    rolls++;
    int s = die[mod(i - 1, 100)] + die[mod(i - 2, 100)] + die[mod(i - 3, 100)];
    p1 = (p1 + s) % 10;
    score1 += pos[p1];
    if (score1 >= 1000) break;

    i = mod(i + 3, 100);
    rolls++;
    s = die[mod(i - 1, 100)] + die[mod(i - 2, 100)] + die[mod(i - 3, 100)];
    p2 = (p2 + s) % 10;
    score2 += pos[p2];
  }
  cout << score1 << ',' << score2 << endl;
  cout << rolls << endl;
  cout << 3 * rolls * min(score1, score2) << endl;
  return 0;
}
