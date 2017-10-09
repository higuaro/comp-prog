#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <list>

using namespace std;

unsigned long factos[] ={1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 8717829120};

string getFactoradic(unsigned int n) {
    // Just cover the case when n is either equal to 0 or 1, if negative also return '0'
    if (n-- <= 1) return string("0");
    size_t elements = sizeof (factos) / sizeof (unsigned long);
    size_t i = 0;
    for (; i < elements; ++i) if (factos[i] > n) break;

    stringstream str;
    while (--i > 0) {
        str << n / factos[i];
        n %= factos[i];
    }
    str << n << '0';
    return str.str();
}

template <typename T> void printPermutation(int index, const list<T>& elements) {

    string factoradic = getFactoradic(index);
    list<T> copy(elements);

    if (elements.size() > factoradic.size()) 
        factoradic.insert(0, elements.size() - factoradic.size(), '0');

    size_t size = factoradic.size();
    
    for (size_t i = 0; i < size; ++i) {
        typename list<T>::iterator ite = copy.begin();
        int index = factoradic[i] - 48;
        advance(ite, index);
        cout << *ite << ',';
        copy.erase(ite);
    }
}

int main() {
//    for (int i = 1; i < 100; ++i)
//        cout << i << " = " << getFactoradic(i) << endl;

    list<int> elem;
    for (int i = 0; i <= 9; ++i) elem.push_back(i);

    printPermutation(1, elem);
    cout << endl;
    printPermutation(3, elem);        
    cout << endl;
    printPermutation(1000000, elem);
    cout << endl;
}
