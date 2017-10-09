#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <limits>

#include <fstream>

using namespace std;
typedef int64_t ullong;

int main() {
//    std::ifstream fis("input02.txt");
//    std::cin.rdbuf(fis.rdbuf());
    
    std::vector<ullong> readXs;
    std::vector<ullong> readYs;
    int t; std::cin >> t;

    while (t--) {
        ullong xCuts = 1L, yCuts = 1L;
        int m; std::cin >> m; int n; std::cin >> n;
        for (int i = 0; i < m - 1; i++) { 
            int temp; std::cin >> temp;
            readYs.push_back(temp);
        }
        for (int i = 0; i < n - 1; i++) { 
            int temp; std::cin >> temp;
            readXs.push_back(temp);
        }

        std::sort(std::begin(readYs), std::end(readYs));
        std::sort(std::begin(readXs), std::end(readXs));
        int xIndex = static_cast<int>(readXs.size()) - 1;
        int yIndex = static_cast<int>(readYs.size()) - 1;

        const ullong MOD = 1000000007L;
        ullong total = 0L;       
        while (yIndex >= 0 || xIndex >= 0) {
            ullong yc = yIndex < 0 ? -1 : readYs[yIndex];
            ullong xc = xIndex < 0 ? -1 : readXs[xIndex];
            
            if (xc > yc) {
                total = (total + ((xc * yCuts) % MOD)) % MOD;
                xIndex--; xCuts++;
            } else {
                total = (total + ((yc * xCuts) % MOD)) % MOD;
                yIndex--; yCuts++;
            }
        }
        std::cout << total << std::endl;
        
        readYs.clear();
        readXs.clear();
    } 
    return 0;
}
