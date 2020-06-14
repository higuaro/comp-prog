#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
  vector<string> h;
  int i;
  int n;
public:
    BrowserHistory(string homepage) {
      h.push_back(homepage); 
      i = 0;
      n = 1;
    }
    
    void visit(string url) {
      i++;  
      n = i + 1;
      if (i >= h.size())
        h.push_back(url);
      else 
        h[i] = url;
    }
    
    string back(int steps) {
      i -= steps; 
      if (i < 0) i = 0;
      return h[i];
    }
    
    string forward(int steps) {
      i += steps;
      if (i >= n)
        i = n - 1;  
      return h[i];
    }
};

