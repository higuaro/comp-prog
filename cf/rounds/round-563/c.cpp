#include <bits/stdc++.h>
using namespace std;

bitset<static_cast<int>(1e5)> primes;
void build_sieve() {
  const int N = 1e5;
  primes.set();
  for (size_t n = 2; n < N; n++) {
    if (!primes[n]) continue;
    for (size_t k = n * n; k < N; k += n) 
      primes.reset(k);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  build_sieve();
  cout << boolalpha;
  for (auto n : ns) 
    cout << n << '=' << primes.test(n) << endl;
  // int n; cin >> n;
  
  return 0;
}
