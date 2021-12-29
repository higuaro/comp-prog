#include <bits/stdc++.h>
using namespace std;

const vector<int> xo{15, 15, 12, 13, -12, 10, -9, 14, 13, -14, -11, -2, -16, -14};
const vector<int> yo{15, 10, 2, 16, 12, 11, 5, 16, 6, 15, 3, 12, 10, 13};
const vector<int> divs{1, 1, 1, 1, 26, 1, 26, 1, 1, 26, 26, 26, 26, 26};
vector<int64_t> max_z;

uint64_t from_digits(const vector<int>& digits) {
  uint64_t r = 0;
  for (int digit : digits)
    r = r * 10 + digit;
  return r;
}

int64_t f(const vector<int>& digits, int i = 0, int64_t z = 0) {
  int w = digits[i];
  return ((z % 26) + xo[i]) != w
      ? 26 * (z / divs[i]) + w + yo[i]
      : z / divs[i];
}

void search(vector<int>& digits, int i = 0, int64_t z = 0) {
  if (i == 14) {
    if (!z)
      cout << "found " << from_digits(digits) << endl;
    return;
  } else if (z <= max_z[i])
    for (int k = 9; k >= 1; k--) {
      digits[i] = k;
      int64_t zz = f(digits, i, z);
      search(digits, i + 1, zz);
    }
}

int main() {
  int64_t mz = 8031810176; // 26 ^ 7
  for (int i = 0; i < 14; i++) {
    max_z.push_back(mz);
    mz /= divs[i];
  }

  vector<int> digits(14, 1);
  search(digits);
  return 0;
}