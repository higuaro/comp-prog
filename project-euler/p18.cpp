#include <cstdlib>
#include <vector>
#include <list>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>

using namespace std;

typedef vector <int> vint;

struct cell {
    vint values;
    int v;
    
    cell(int v) : values{}, v{v} {}
};

int main() {
    ifstream fin("b.txt");

    vector< vector<cell> > sums;
    
    size_t num_lines = 100;
    for (size_t i = 0; i < num_lines; ++i) {
        vector<cell> line;
        for (size_t j = 0; j <= i; ++j) {
            int v;
            fin >> v;
            line.push_back(v);
            if (i == 0) line[0].values.push_back(v);
        }

        sums.push_back(line);

        if (i > 0) {
            vector<cell>& prev = sums[i - 1];
            vector<cell>& cur = sums[i];

            for (size_t j = 0; j < i; ++j) {
                vint::iterator ite = prev[j].values.begin();
                vint::iterator end = prev[j].values.end();
                for (; ite != end; ++ite) {
                    cur[j].values.push_back((*ite) + cur[j].v);
                    cur[j + 1].values.push_back((*ite) + cur[j + 1].v);
                }
            }
        }
cout << "row " << i + 1 << endl;
    }

    vector< cell >& last_line = sums[num_lines - 1];

    int max = INT_MIN;
    for (size_t i = 0; i < num_lines; ++i) {
        vint::iterator ite = last_line[i].values.begin();
        vint::iterator end = last_line[i].values.end();
        for (; ite != end; ++ite)
            if ((*ite) > max) max = (*ite);
    }
    
    cout << max << endl;
}
