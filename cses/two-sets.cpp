#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
  uint64_t n; cin >> n;
  uint64_t sum = n * (n + 1) / 2;
  if (sum & 1){
    cout << "NO" << endl;
    return 0;
  }

  unordered_set<uint64_t> nums;
  uint64_t half = sum / 2;
  for (uint64_t k = n; k >= 1; k--) {
    if (half <= k) {
      nums.insert(half);
      break;
    }
    nums.insert(k);
    half -= k;
  }
  cout << "YES\n";
  cout << nums.size() << endl;
  for (const auto ni : nums) cout << ni << ' ';
  cout << '\n';
  cout << n - nums.size() << endl;
  for (int k = 1; k <= n; k++)
    if (!nums.count(k)) cout << k << ' ';
  cout << '\n';
  return 0;
}
