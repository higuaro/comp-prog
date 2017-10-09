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
#include <cstring>

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("10703.FreeSpots.in");
    std::cin.rdbuf(fis.rdbuf());
#endif  
    const size_t kMaxSize = 500;
    bool spots[kMaxSize][kMaxSize];
    size_t w, h, n; 
    while (std::cin >> w >> h >> n && (w || h || n)) {
        memset(spots, 0, sizeof(spots[0][0]) * kMaxSize * kMaxSize);
        for (size_t i = 0; i < n; i++) { 
            size_t x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2) std::swap(x1, x2); 
            if (y1 > y2) std::swap(y1, y2);
            for (size_t x = x1 - 1; x < x2; x++)
                for (size_t y = y1 - 1; y < y2; y++) 
                    spots[x][y] = true;
        }

        size_t free = 0;
        for (size_t x = 0; x < w; x++)
            for (size_t y = 0; y < h; y++)
                if (!spots[x][y]) free++;

        switch (free) {
            case 0: std::cout << "There is no empty spots." << std::endl; break;
            case 1: std::cout << "There is one empty spot." << std::endl; break;
            default: std::cout << "There are " << free << " empty spots." << std::endl; break;
        }
    }
    return 0;
}