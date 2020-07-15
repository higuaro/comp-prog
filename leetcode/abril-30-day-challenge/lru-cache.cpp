#include <bits/stdc++.h>
using namespace std;

class LRUCache {
  static const int oo = numeric_limits<int>::max();
  typedef list<pair<int, int>> cache_t;
  cache_t cache;
  unordered_map<int, cache_t::iterator> pos;
  int capacity;
  int size;

public:
  LRUCache(int capacity) : capacity(capacity), size(0) {}

  int get(int key) {
    if (!pos.count(key)) return -1;
    auto ite = pos[key];
    auto [k, v] = *ite;
    cache.erase(ite);
    pos[key] = cache.insert(begin(cache), {k, v});
    return v;
  }

  void put(int key, int value) {
    bool should_remove = pos.count(key) || size >= capacity;
    if (should_remove) {
      int k = pos.count(key) ? key : cache.back().first;
      cache.erase(pos[k]);
      pos.erase(k);
      size--;
    }
    pos[key] = cache.insert(begin(cache), {key, value});
    size++;
  }
};

int main() {
  LRUCache lru(2);
  cout << lru.get(2) << endl;
  lru.put(2, 6);
  cout << lru.get(1) << endl;
  lru.put(1, 5);
  lru.put(1, 2);
  cout << lru.get(1) << endl;
  cout << lru.get(2) << endl;
  return 0;
}
