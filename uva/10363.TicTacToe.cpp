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

typedef std::vector< std::vector<char> > board_t;

board_t readBoard(std::istream& cin) {
    board_t board(3);
    std::string line;
    for (size_t i = 0; i < 3; i++) {
        std::getline(cin, line);
        for (size_t j = 0; j < 3; j++)
            board[i].push_back(line[j]); 
    }
    std::getline(cin, line);
    return board;
}

bool isValidBoard(const board_t& board) { 
    const size_t masks[] = { 0b0111000000, 0b000111000, 0b000000111, 0b0100100100, 0b010010010, 0b001001001, 0b0100010001, 0b001010100 };
    size_t x = 0;
    size_t o = 0;
    size_t stateX = 0, stateO = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') { 
                stateX |= 1 << (8 - ((3 * i) + j));
                x++;
            } else if (board[i][j] == 'O') { 
                stateO |= 1 << (8 - ((3 * i) + j));
                o++;
            }
        }
    }
    if (x < o) return false;    
    if (x >= o && (x - o) > 1) return false;

    size_t winsX = 0, winsO = 0;
    for (int i = 0; i < 8; i++) {
        if ((masks[i] & stateX) == masks[i]) winsX++;
        if ((masks[i] & stateO) == masks[i]) winsO++;        
    }
    if (winsX > 0 && winsO > 0) return false;
    if (winsO > 1) return false;
    if (winsX == 1 && x <= o) return false;  
    if (winsO == 1 && x != o) return false;      
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("TicTacToe.in");
    std::cin.rdbuf(fis.rdbuf());
#endif
    int n;
    std::cin >> n; std::cin.ignore(255, '\n');
    while (n--) 
        std::cout << (isValidBoard(readBoard(std::cin)) ? "yes" : "no") << std::endl; 
    return 0;
}