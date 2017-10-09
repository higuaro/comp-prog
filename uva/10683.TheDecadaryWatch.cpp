#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

// I was using a more accurate convertion, using floating point, which 
// would print 9999999 for the test case 23595999 (as exposed in the problem 
// statement), 

// std::string convertTo10(const size_t ms) {
//     const double kTotalCsDay = (23.0 * 3600.0 + 59 * 60 + 59) * 100 + 99;
//     return std::to_string(static_cast<size_t>((static_cast<double>(ms) / kTotalCsDay) * 9999999.0));
// }

// it turned out that the uva toolkit and uva debug were printing 
// 9999998 for that test case, and of course there were several other test 
// cases that didn't work, to spot the differences between my floating point 
// version and the uva toolkit, I wrote a program that prints all the input cases
// and then feed uva debug with the last 2000 lines. I got several differences,
// then saw that people were using integer div and well...

size_t convertTo10(const size_t ms) {
    return (ms * 10000000) / ((23 * 3600 + 59 * 60 + 59) * 100 + 100);
}
int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
    std::ifstream fis("TheDecadaryWatch.in");
    std::cin.rdbuf(fis.rdbuf());
#endif
    std::string line;
    while (std::cin >> line) {
        size_t h = std::stoi(line.substr(0, 2));
        size_t m = std::stoi(line.substr(2, 2));
        size_t s = std::stoi(line.substr(4, 2));
        size_t c = std::stoi(line.substr(6, 2));

        size_t ms = (h * 3600 + m * 60 + s) * 100 + c;
        std::cout << std::setfill('0') << std::setw(7) << convertTo10(ms) << std::endl;
    }
    return 0;
}