#include <cstring>
#include <iostream>
#include <vector>

template<typename Type> 
std::vector< std::vector<Type> > createTable(const size_t numRows, const size_t numCols, Type defaultValue = Type()) { 
    std::vector< std::vector<Type> > table;
    for (size_t i = 0; i < numRows; ++i)
        table.push_back(std::vector<Type>(numCols, defaultValue));
    return table;
}

int coinChangeCount(const int change, const std::vector<int>& coinValues) {
    const int COINS = coinValues.size();
    std::vector< std::vector<int> > memo = createTable(change + 1, COINS + 1, 0);
    for (int i = 1; i < COINS + 1; i++) memo[0][i] = 1;
    for (int c = 1; c < change + 1; c++)
        for (int j = 1; j < COINS + 1; j++)
            memo[c][j] = memo[c][j - 1] + (c - coinValues[j - 1] >= 0 ? memo[c - coinValues[j - 1]][j] : 0);
    return memo[change][COINS];
}

int main(int argc, char** argv) {
    /* 
    // This works!
    const int CHANGE = 200;
    const int COINS = 8;
    const int coinValues[COINS] = { 1, 2, 5, 10, 20, 50, 100, 200 }; 
    
    int memo[CHANGE + 1][COINS + 1];
    memset(memo, 0, sizeof(int) * (CHANGE + 1) * (COINS + 1));
    
    for (int i = 1; i < COINS + 1; i++) memo[0][i] = 1;
    
    for (int c = 1; c < CHANGE + 1; c++)
        for (int j = 1; j < COINS + 1; j++)
            memo[c][j] = memo[c][j - 1] + (c - coinValues[j - 1] >= 0 ? memo[c - coinValues[j - 1]][j] : 0);
    std::cout << memo[CHANGE][COINS] << std::endl;
    */
    
    std::vector<int> coinValues = { 1, 2, 5, 10, 20, 50, 100, 200 };
    std::cout << coinChangeCount(200, coinValues) << std::endl;
    return 0;
}