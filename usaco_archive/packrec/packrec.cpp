/*
ID: henry.e1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <climits>
#include <list>
#include <functional>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef list< pair<int, int> > listPairs;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

string getFactoradic(unsigned int n) {
    unsigned long factos[] ={1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 8717829120};

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

template <typename T> list<T> getPermutation(int index, const list<T>& elements) {
    string factoradic = getFactoradic(index);
    list<T> copy(elements);

    if (elements.size() > factoradic.size()) 
        factoradic.insert(0, elements.size() - factoradic.size(), '0');

    size_t size = factoradic.size();
    
    list<T> result;
    
    for (size_t i = 0; i < size; ++i) {
        typename list<T>::iterator ite = copy.begin();
        int index = factoradic[i] - 48;
        advance(ite, index);
        result.push_back(*ite);
        copy.erase(ite);
    }
    
    return result;
}

inline void checkMinArea(int w, int h, int& minArea, listPairs& mins) { 
    int area = w * h;
    if (area < minArea) { 
        minArea = area;
        mins.clear();
        mins.push_back(pair<int, int>(w > h ? h : w, w > h ? w : h));
    } else if (area == minArea) { 
        mins.push_back(pair<int, int>(w > h ? h : w, w > h ? w : h));
    }
}

int main() {
    ifstream fin("packrec.in");
    ofstream fout("packrec.out");

    listPairs boxes;
    listPairs mins;
    int minArea = INT_MAX;
    int pows[] = {1, 2, 4, 8, 16};

    int w[4], h[4];
    fill(w, w + 4, 0);
    fill(h, h + 4, 0);

    // Read the first
    pair<int, int> b;    
    while (fin >> b.first  >> b.second) {
        boxes.push_back(b);

        // Read the rest
        for (int i = 1; i < 4; ++i) {
            fin >> b.first >> b.second;
            boxes.push_back(b);
        }
        
        for (size_t k = 0; k < 24; k++) {
            listPairs permu = getPermutation(k, boxes);

            for (int rot = 0; rot < 16; ++rot) {
                listPairs::iterator ite = permu.begin();
                listPairs::iterator end = permu.end();
                
                int coord = 0;
                for (; ite != end; ++ite, ++coord) { 
                    w[coord] = (*ite).first;
                    h[coord] = (*ite).second;
                    
                    if ( ((rot / pows[coord]) % 2) == 1 ) {
                        int temp = w[coord];
                        w[coord] = h[coord];
                        h[coord] = temp;
                    }                    
                }
                
                int W = 0, H = 0;
                W = accumulate(w, w + 4, 0);
                H = *max_element(h, h + 4);
                checkMinArea(W, H, minArea, mins);

                if (w[1] > w[0]) { 
                    W = accumulate(w + 1, w + 4, 0);
                    H = max(h[0] + h[1], *max_element(h + 2, h + 4));                    
                } else { 
                    W = max(w[0], accumulate(w + 1, w + 4, 0));
                    H = h[0] + *max_element(h + 1, h + 4);
                } 
                checkMinArea(W, H, minArea, mins);

                W = max(w[0], w[1] + w[2]) + w[3];
                H = max(h[0] + max(h[1], h[2]), h[3]);
                checkMinArea(W, H, minArea, mins);

                W = w[0] + max(w[1], w[2]) + w[3];
                H = max(h[3], max(h[0], h[1] + h[2]));
                checkMinArea(W, H, minArea, mins);

                W = max(w[0], w[1]) + w[2] + w[3];
                H = max(h[3], max(h[0] + h[1], h[2]));
                checkMinArea(W, H, minArea, mins);

                if (h[1] == h[2]) {
                    H = h[1] + max(h[0], h[3]);
                    W = max(w[1] + w[2], w[0] + w[3]);
                    checkMinArea(W, H, minArea, mins);
                } else {
                    if (h[2] > h[0] + h[1]) {
                        H = h[2] + h[3];
                        W = max(max(w[0], w[1]) + w[2], w[3]);
                        checkMinArea(W, H, minArea, mins);
                        continue;
                    } else if (h[2] > h[1] && w[1] > w[0]) { 
                        H = max(h[0] + h[1], h[2] + h[3]);
                        W = max(w[1] + w[2], w[0] + w[3]);

                        checkMinArea(W, H, minArea, mins); 

                        continue;                        
                    }

                    if (h[1] > h[2] + h[3]) {
                        H = h[1] + h[0];
                        W = max(max(w[2], w[3]) + w[1], w[0]);
                        checkMinArea(W, H, minArea, mins);
                        continue;                        
                    } else if (h[1] > h[2] && w[2] > w[3]) { 
                        H = max(h[0] + h[1], h[2] + h[3]);
                        W = max(w[1] + w[2], w[0] + w[3]);
                        
                        checkMinArea(W, H, minArea, mins);                        
                        continue;
                    } 

                    H = max(h[0] + h[1], h[2] + h[3]);
                    W = max(w[0], w[1]) + max(w[2], w[3]);                        
                    checkMinArea(W, H, minArea, mins);                    
                }                
            }
        }        
        
        mins.sort(cmp);
        mins.unique();

        fout << minArea << endl;
        listPairs::iterator ite, end;
        for (ite = mins.begin(), end = mins.end(); ite != end; ++ite)
            fout << ite->first << ' ' << ite->second << endl;
    }
    return 0;
}