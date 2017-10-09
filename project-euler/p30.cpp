/* 
 * File:   p30.cpp
 * Author: higuaro
 *
 * Created on 13 de julio de 2011, 12:26 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#define F(x) x * x * x * x * x
typedef unsigned long ulong;
    
int main(int argc, char** argv) {
    size_t powers[] = {F(0), F(1), F(2), F(3), F(4), F(5), F(6), F(7), F(8), F(9) }; 

    ulong t = 0;
    for (size_t i = 2; i < 100000000; i++) { 
        ulong s = 0;        
        for (size_t j = 0, b = 1; j < 8; j++, b *= 10) s += powers[(i / b) % 10];
        if (s == i) {
            cout << i << endl;
            t += i;
        }            
    }
    cout << endl << t << endl;
    return 0;
}

