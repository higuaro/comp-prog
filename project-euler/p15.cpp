#include <cstdlib>
#include <cmath>
#include <iostream>
#include <inttypes.h>

using namespace std;

typedef unsigned char uchar;
typedef uint64_t ulong;

ulong total_routes = 0;

unsigned int W = 3 + 1;
unsigned int H = 3 + 1;

void count_moves(size_t pos_i, size_t pos_j) { 
    if (pos_i >= H) return;
    if (pos_j >= W) return;    
    
    if (pos_i == H - 1 && pos_j == W - 1) { 
        total_routes++;
        return;
    } else {
        count_moves(pos_i + 1, pos_j);
        count_moves(pos_i, pos_j + 1);
    }
}

int main() { 
    const size_t W = 20 - 1;
    const size_t H = 20 - 1;
    ulong grid[W][H];
    grid[0][0] = 6;
    for (size_t i = 1; i < W; i++) grid[0][i] = grid[0][i - 1] + 3 + i;
    for (size_t i = 1; i < H; i++) grid[i][0] = grid[i - 1][0] + 3 + i;
             
    for (size_t i = 1; i < W; i++) { 
        for (size_t j = 1; j < H; j++) { 
            grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
        }
    }
    /*
    for (size_t i = 2; i < 15; i++) { 
        for (size_t j = 2; j < 15; j++) { 
            W = i + 1;
            H = j + 1;
            total_routes = 0;
            count_moves(0, 0);
            cout << "(" << W - 1 << "," << H - 1 << ")=" << total_routes << endl;
        }
    }
    */
    cout << grid[0][0] << endl;
    cout << grid[1][0] << endl;    
    cout << grid[2][0] << endl;        
    cout << grid[0][2] << endl;            
    cout << grid[1][1] << endl;                
    cout << grid[2][2] << endl;               
    cout << grid[3][3] << endl;
    cout << grid[18][18] << endl;
    return 0;
}


