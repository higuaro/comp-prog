#include <iostream>
#include <algorithm>
#include <sstream>

bool isPandigical(const std::string& n) {
    int mask = 0;
    std::for_each(n.begin(), n.end(), [&mask](char c) { 
        mask |= 1 << static_cast<int>(c - '0');
    });
    return mask == (0x1ff << 1);
}
int generateMaxPandigicalForK(int k) {
    int maxPandigical = 0;
    for (int n = 1; n <= 9; n++) {
        std::stringstream res;
        for (int i = 1; i <= n; i++)
            res << (k * i);
        std::string v = res.str();
        if (v.size() == 9 && isPandigical(v))
            maxPandigical = std::max(maxPandigical, std::stoi(v));
    }
    return maxPandigical;
}
int main() {
    // Bounds adjusted from user's @CapnP comment
    const int SEARCH_LIMIT = 9999; 
    int max = 0;
    for (int k = 9000; k < SEARCH_LIMIT; k++)
        max = std::max(max, generateMaxPandigicalForK(k));
    std::cout << max << std::endl;
    return 0;
}
