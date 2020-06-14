#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
      vector<int> sums;
      int s = 0;
      for (int i = 0; i < nums.size(); i++) {
        s += nums[i];
        sums.push_back(s);
      }
       return sums;
    }
};
