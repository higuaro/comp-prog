#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int pivot_index(int lo, int hi, const vector<int>& nums) {
    if (lo >= hi) return lo;
    
    int m = (lo + hi) / 2;
    if (nums[m] > nums[m + 1]) 
      return m + 1;
    
    if (nums[lo] > nums[m]) 
      return pivot_index(lo, m, nums);
    if (nums[m + 1] > nums[hi])
      return pivot_index(m + 1, hi, nums);
    return 0;
  }
  int b_search(int lo, int hi, const vector<int>& nums, int t, int n, int o) {
    if (lo > hi) return -1;
    int m = (lo + hi) / 2;
    int mo = (m + o) % n;
    
    if (nums[mo] == t) return mo;
    
    if (t < nums[mo]) 
      return b_search(lo, m - 1, nums, t, n, o);
    
    if (t > nums[mo])
      return b_search(m + 1, hi, nums, t, n, o);
    return -1;
  }
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int p = pivot_index(0, n - 1, nums);    
    return b_search(0, n - 1, nums, target, n, p);  
  }
};
