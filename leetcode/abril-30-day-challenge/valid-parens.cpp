#include <bits/stdc++.h>
using namespace;

class Solution {
public:
    bool checkValidString(string s) {
      int stars = 0;
      int pars = 0;
      const int n = s.size();
      for (int i = 0; i < n; i++) {
        char c = s[i];
        switch (c) {
          case '(': pars++; break;
          case ')': pars--; break;
          case '*': stars++;  
        }
        if (pars < 0) {
          if (stars) {
            stars--; pars++;
          } else 
            return false;
        }
      }
      stars = pars = 0;
      for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        switch (c) {
          case ')': pars++; break;
          case '(': pars--; break;
          case '*': stars++;  
        }
        if (pars < 0) {
          if (stars) {
            stars--; pars++;
          } else 
            return false;
        }
      }
      return true;
    }
};
