#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      int prev = numeric_limits<int>::max();
      int count = 0;
      vector<int> c;
      sort(begin(arr), end(arr));
      for (int i = 0; i < arr.size(); i++) {
        int v = arr[i];
        if (prev == v) {
          count++;
        } else {
          if (count)
            c.push_back(count);
          count = 1;
          prev = v;
        }
      }  
      c.push_back(count);

      sort(begin(c), end(c));
      
      int removed = 0;
      for (int i = 0; k > 0 && i < c.size(); i++) {
        if (c[i] <= k) {
          k -= c[i];
          removed++;
        } else {
          break;
        }
      }
      return static_cast<int>(c.size()) - removed;
    }
};
