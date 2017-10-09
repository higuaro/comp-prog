#include <iostream>
#include <cmath>
#include <random>
// Input generator for Algorithmic Crush
int main(int argc, char* argv[]) {
    const int max_range = std::atoi(argv[1]);
    const int num_queries = std::atoi(argv[2]);
    std::cout << max_range << " " << num_queries << std::endl;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, max_range);
    std::uniform_int_distribution<> dist_k(0, 100);

    for (int i = 0; i < num_queries; ++i) {
        int a = dist(mt);
        int b = dist(mt);
        int k = dist_k(mt);

        std::cout << std::min(a, b) << ' ' << std::max(a, b) << ' ' << k << std::endl;
    }
    return 0;
}
