#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>

using namespace std;

string richieRich(string s, int n, int k){
    // Complete this function
    int size = s.size();
    int mid = size / 2;
    int different = 0;
    for (int i = 0, j = size - 1; i < mid; i++, j--)
        if (s[i] != s[j]) different++;

    if (different > k) return "-1";

    // 123901 k = 3 
    // 1230901 k = 5 9990999
    // 1230901 k = 5 9999999
    for (int i = 0, j = size - 1; i < mid; i++, j--) {
        char l = s[i], r = s[j];
        if (l == r) {
            if (l == '9') continue;
            if (k - different >= 2) {
                s[i] = s[j] = '9';
                k -= 2;
            }
        } else {
            if (l == '9' || r == '9') {
                s[i] = s[j] = '9';
                k--;
            } else if (k - different >= 1) {
                s[i] = s[j] = '9';
                k -= 2;
            } else {
                s[i] = s[j] = l > r ? l : r;
                k--;
            }
            different--;
        }
    }

    if (k && (size & 1)) { 
        s[mid] = '9';
        k--;
    }

    return s;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}
