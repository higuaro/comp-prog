#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  int N = pow(2, n);
  cerr << N << endl;
  for (int i = 0; i < N; i++) {
    bitset<200> b(i);
    cout << b.to_string() << endl;
    uint64_t k = 0;
    int kk = 0;
    for (int i = 0; i < 200; i++) {
      if (b.test(i)) {
        k += a[i];
        kk++;
      }
    }

    if (!(k % 200ULL) && kk > 1) {
      cout << "Yes" << endl;
      cout << "1 ";
      int j = 0;
      for (; j < 200; j++) {
        if (b.test(j)) {
          cout << (j + 1) << endl;
          break;
        }
      }
      cout << (kk - 1) << ' ';
      for (j++; j < 200; j++) {
        if (b.test(j))
          cout << (j + 1) << ' ';
      }
      cout << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
