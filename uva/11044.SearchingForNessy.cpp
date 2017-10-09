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

int count(const int n) {
    return (n / 3) + ((n % 3) > 0 ? 1 : 0); 
}
int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("11044.SearchingForNessy.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    int n; std::cin >> n;
    while (--n >= 0) {
        int w, h; std::cin >> w >> h;
        std::cout << count(w - 2) * count(h - 2) << std::endl; 
    }
    return 0;
}