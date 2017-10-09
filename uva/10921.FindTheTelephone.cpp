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


int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("10921.FindTheTelephone.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    std::string line;
    while (std::getline(std::cin, line)) {
        for (char c : line) {
            char d = c;
            switch (c) {
                case 'A': case 'B': case 'C': d = '2' ;break;
                case 'D': case 'E': case 'F': d = '3' ;break;
                case 'G': case 'H': case 'I': d = '4' ;break;
                case 'J': case 'K': case 'L': d = '5' ;break;
                case 'M': case 'N': case 'O': d = '6' ;break;
                case 'P': case 'Q': case 'R': case 'S': d = '7' ;break;
                case 'T': case 'U': case 'V': d = '8' ;break;
                case 'W': case 'X': case 'Y': case 'Z': d = '9' ;break;
            }
            std::cout << d;
        }
        std::cout << std::endl;
    }
    return 0;
}