
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
const size_t SIZE = 1001;
/*  
void p(size_t m[SIZE][SIZE]) {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++)
            cout << m[i][j] << " ";            
        cout << endl;
    }    
}
*/
int main(int argc, char** argv) {


    size_t m[SIZE][SIZE];
    memset(m, 0, SIZE * SIZE * sizeof(size_t));
    
    size_t ci = (SIZE / 2);
    size_t cj = ci;
    
    size_t LIMIT = SIZE * SIZE;
    int offset_j[] = { 1, 0, -1, 0 };
    int offset_i[] = { 0, 1, 0, -1 };
    size_t offset = 0;
    size_t size = 2, turnCount = 0;    
    unsigned long total = 0;
    for (size_t i = 1, c = 1; i <= LIMIT; i++, c++) { 
        m[ci][cj] = i;
        if (ci == cj || ci + cj == SIZE - 1) total += i; 
        
        if (c == size) {
            turnCount++;
            offset++;
            c = 1;
        }
        if (turnCount == 2) { 
            size++;
            turnCount = 0;
        }
        ci += offset_i[offset % 4];
        cj += offset_j[offset % 4];    
    }
    cout << total << endl;
    //p(m);

    return 0;
}



