#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int mod(int k, int n) {
  return ((k % n) + n) % n;
}
int happiness(const vector<int>& p) {
  int n = p.size();
  int h = 0;
  for (int i = 0; i < n; i++) {
    if (p[n - 1 - mod(i + 1, n)] == i
        || p[n - 1 - i] == i
        || p[n - 1 - mod(i - 1, n)] == i)
      h++;
  }
  return h;
}
int main() {
  int n; cin >> n;
  vector<int> v;
  unordered_map<int, int> p;
  unordered_map<int, int> h;
  for (int i = n - 1; i >= 0; i--) {
    int pi; cin >> pi;
    v.push_back(pi);
    p[pi] = i;
    h[mod(i - pi - 1, n)]++;
    h[mod(i - pi, n)]++;
    h[mod(i - pi + 1, n)]++;
  }
  vector<pair<int, int>> m;
  for (const auto& [k, v]: h)
    m.emplace_back(v, k);
  sort(m.begin(), m.end(), greater<>());

  int max_h = 0;
  for (int i = 0; i < min(3, static_cast<int>(m.size())); i++) {
    int rots = m[i].first;
    //cout << rots << endl;
    vector<int> c(n);
    rotate_copy(v.begin(), v.begin() + rots, v.end(), c.begin());
    //for (auto ci : c)
    //  cout << ci << ',';
    //cout << endl;
    //cout << 'h' << happiness(c) << endl;
    max_h = max(max_h, happiness(c));
  }
  cout << max_h << endl;
  return 0;
}
