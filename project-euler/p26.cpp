/* 
 * File:   p26.cpp
 * Author: higuaro
 *
 * Created on 28 de mayo de 2012, 11:37 PM
 */

#include <cstdlib>
#include <map>
#include <iostream>
        
using namespace std;

typedef unsigned int uint;

int main(int argc, char** argv) {
    const uint kStart = 2;
    const uint kEnd = 1000;
    map<uint, uint> res;
    uint max = 0;
    uint maxD = 0;
    
    for (uint d = kStart; d < kEnd; d++) { 
        
        res.clear();
        uint div = 10;
        uint resCount = 0;
        uint mod = 0;
        bool found = false;
        do {
            if (div > d) mod = div % d;
            else mod = div;
            
            if (!mod) break;
            
            if (res.count(mod)) {
                uint loopLen = resCount - res[mod];
                if (loopLen > max) { max = loopLen; maxD = d; }
                found = true;
            }
            res[mod] = resCount++;
            if (div > d) div %= d;
            div *= 10;
        } while (!found);
    }
    cout << maxD << endl;
    cout << max << endl;
    return 0;
}

