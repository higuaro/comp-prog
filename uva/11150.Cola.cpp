#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <limits>
#include <iomanip>
#include <cstdint>

int cola(int filled, int empty, int borrow) {
    empty += filled;    
    if (filled == 0) return 0;
    if (empty == borrow) return filled;
 
    if ((empty % 3) == 2 && ((empty + 1) / 3) >= borrow + 1) 
        return filled + cola((empty + 1) / 3, 0, borrow + 1);
    
    if ((empty / 3) + (empty % 3) >= borrow) {
        return filled + cola(empty / 3, empty % 3, borrow);
    } else {
        int reserved = 0;
        while (empty > 3) {
            empty -= 3;
            reserved += 3;
            if ((empty / 3) + (empty % 3) + reserved >= borrow) { 
                return filled + cola(empty / 3, (empty % 3) + reserved, borrow);
            }
        }
    }
    return filled;
}

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("11150.Cola.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << cola(std::stoi(line), 0, 0) << std::endl;
    }
    return 0;
}