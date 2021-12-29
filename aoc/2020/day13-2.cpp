#include <bits/stdc++.h>
using namespace std;
// Multiplicative inverse function taken from:
// https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
uint64_t inverse(uint64_t a, uint64_t m) {
  int64_t m0 = m, t, q;
  int64_t x0 = 0LL, x1 = 1LL;
  if (m == 1LL) return 0LL;

  while (a > 1LL) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  return x1 < 0LL ? x1 + m0 : x1;
}
uint64_t crt(const vector<int>& rem, const vector<int>& mod) {
  int n = rem.size();
  uint64_t prod = accumulate(begin(mod), end(mod), 1ULL, multiplies<uint64_t>());
  uint64_t ans = 0ULL;
  for (int i = 0; i < n; i++) {
    uint64_t pp = prod / mod[i];
    uint64_t inv = inverse(pp, mod[i]);
    ans += static_cast<uint64_t>(rem[i]) * inv * pp;
  }
  return ans % prod;
}
int main() {
  int _; cin >> _;
  string line;
  int t = 0;
  vector<int> times;
  vector<int> buses;
  while (getline(cin, line, ',')) {
    if (line != "x") { 
      int bus_id = stoi(line);
      buses.push_back(bus_id);
      times.push_back(bus_id - t);
    }
    t++;
  }
  int n = buses.size();
  for (int i = 0; i < n; i++)
    cout << "t ≡ " << times[i] << " (mod " << buses[i] << ")" << endl;

  cout << crt(times, buses) << endl;
  return 0;
}
