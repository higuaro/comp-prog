#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
      sort(begin(arr), end(arr));
      int n = arr.size();
      int m = arr[((n - 1) / 2)]; 
      sort(begin(arr), end(arr), [=](const int& i, const int& j) {
        int d = abs(i - m) - abs(j - m);
        return (!d ? (i > j) : (d > 0));
      });
      vector<int> r;
      for (int i = 0; i < k; i++) 
        r.push_back(arr[i]);
      return r;
    }
};
