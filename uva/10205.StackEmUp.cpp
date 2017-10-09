#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<typename Type> 
std::vector< std::vector<Type> > createTable(size_t numRows, size_t numCols, Type defaultValue = Type()) { 
    std::vector< std::vector<Type> > table;
    for (size_t i = 0; i < numRows; ++i) { 
        table.push_back(std::vector<Type>(numCols, defaultValue));
    }
    return table;
}

string getCardName(size_t card) {
    size_t suitIndex = card / 13;
    size_t value = card % 13;
    string name;
    if (value < 8) { 
        name = static_cast<char>(value + '2');
    } else { 
        switch (value) { 
            case 8: name = "10"; break;        
            case 9: name = "Jack"; break;        
            case 10: name = "Queen"; break;
            case 11: name = "King"; break;        
            case 12: name = "Ace";
        }
    }
    
    switch (suitIndex) { 
        case 0: name += " of Clubs"; break;
        case 1: name += " of Diamonds"; break;
        case 2: name += " of Hearts"; break;
        case 3: name += " of Spades"; break;
    }
    return name;
}

int main() {
#ifndef ONLINE_JUDGE
    ifstream fis("StackEmUp.in");
    cin.rdbuf(fis.rdbuf());
#endif

    int numTestCases = 0;
    cin >> numTestCases;
    
    string cardNames[52];
    for (size_t i = 0; i < 52; i++) cardNames[i] = getCardName(i);
    
    while(numTestCases--) {
        string line;
        // read empty line
        getline(cin, line);
        
        vector<size_t> cards(52);
        for (size_t i = 0; i < 52; i++) cards[i] = i;
        
        int n;
        cin >> n;
        cin.ignore(255, '\n');
        vector< vector<size_t> > shuffles = createTable<size_t>(n, 52, 0);

        for (int i = 0; i < n; i++) { 
            for (size_t j = 0; j < 52; j++) {
                size_t index;
                cin >> index;
                shuffles[i][j] = index - 1;
            }
        }

        vector<size_t> res(cards);
        for (int i = 0; i < n; i++) { 
            size_t applyShuffle;
            cin >> applyShuffle;
            vector<size_t> temp(52);
            for (size_t j = 0; j < 52; j++) {
                size_t cardIndex = shuffles[applyShuffle - 1][j];
                temp[j] = res[cardIndex];
            }
            res = temp;
        }
        
        for (size_t i = 0; i < 52; i++) cout << cardNames[res[i]] << endl;
        if (numTestCases) cout << endl;
    }
    
    return 0;
}
