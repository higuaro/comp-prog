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

void skipLines(std::istream& cin, size_t numLines) {
    for (size_t i = 0; i < numLines; i++) cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("RequestForProposal.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    int n, p; std::cin >> n >> p; std::cin.ignore(256, '\n');
    int numCases = 1;
    while (n && p) {
        double compliance = std::numeric_limits<double>::min();
        double price = std::numeric_limits<double>::max(); 

        std::string bestPropName;
        skipLines(std::cin, n);

        for (int i = 0; i < p; i++) {
            std::string name; std::getline(std::cin, name);
            double d; int r;
            std::cin >> d >> r; std::cin.ignore(256, '\n');
            double c = static_cast<double>(r) / static_cast<double>(n);
            if (c > compliance || (c == compliance && d < price)) {
                compliance = c;
                price = d;
                bestPropName = name;
            } 
            skipLines(std::cin, r);
        }

        if (numCases > 1) std::cout << std::endl;
        std::cout << "RFP #" << numCases++ << std::endl;
        std::cout << bestPropName << std::endl;

        std::cin >> n >> p; std::cin.ignore(256, '\n');
    }        
    return 0;
}