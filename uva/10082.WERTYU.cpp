#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("WERTYU.in");
    std::cin.rdbuf(fis.rdbuf());
#endif
    std::string alphabet("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
    std::string line;
    while (std::getline(std::cin, line)) {
        std::string result;
        for (char c : line) {
            size_t index = alphabet.find(c);
            result += index > 0 && index != std::string::npos ? alphabet[index - 1] : c;
        }
        std::cout << result << std::endl;
    }
    return 0;
}