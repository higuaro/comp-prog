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
#include <map>
#include <cstdint>

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("11223.DahDahDah.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    int t; std::cin >> t; 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::map<std::string, char> code;
    
    // while read LINE; do C=`cut -d" " -f1 <<<"$LINE"`; V=`cut -d" " -f2 <<<"$LINE"`; echo -e " code[\"$V\"] = '$C';"; done < codes.txt
    
    code[".-"] = 'A';
    code[".---"] = 'J';
    code["..."] = 'S';
    code[".----"] = '1';
    code[".-.-.-"] = '.';
    code["---..."] = ':';
    code["-..."] = 'B';
    code["-.-"] = 'K';
    code["-"] = 'T';
    code["..---"] = '2';
    code["--..--"] = ',';
    code["-.-.-."] = ';';
    code["-.-."] = 'C';
    code[".-.."] = 'L';
    code["..-"] = 'U';
    code["...--"] = '3';
    code["..--.."] = '?';
    code["-...-"] = '=';
    code["-.."] = 'D';
    code["--"] = 'M';
    code["...-"] = 'V';
    code["....-"] = '4';
    code[".----."] = '\'';
    code[".-.-."] = '+';
    code["."] = 'E';
    code["-."] = 'N';
    code[".--"] = 'W';
    code["....."] = '5';
    code["-.-.--"] = '!';
    code["-....-"] = '-';
    code["..-."] = 'F';
    code["---"] = 'O';
    code["-..-"] = 'X';
    code["-...."] = '6';
    code["-..-."] = '/';
    code["..--.-"] = '_';
    code["--."] = 'G';
    code[".--."] = 'P';
    code["-.--"] = 'Y';
    code["--..."] = '7';
    code["-.--."] = '(';
    code[".-..-."] = '"';
    code["...."] = 'H';
    code["--.-"] = 'Q';
    code["--.."] = 'Z';
    code["---.."] = '8';
    code["-.--.-"] = ')';
    code[".--.-."] = '@';
    code[".."] = 'I';
    code[".-."] = 'R';
    code["-----"] = '0';
    code["----."] = '9';
    code[".-..."] = '&';
    
    int caseNumber = 1;
    while (t--) {
        std::string line;
        std::getline(std::cin, line);
        std::string buffer;
        std::string message;
        bool alreadyPrintedSpace = false;
        bool atLeastOneChar = false;
        for (char c : line) {
            switch (c) {
                case ' ':
                    if (!buffer.empty()) {
                        message += code[buffer];
                        buffer.clear();
                    } else {
                        if (atLeastOneChar && !alreadyPrintedSpace) {
                            message += ' ';
                            alreadyPrintedSpace = true;
                        }
                    }
                    break;
                default:
                    alreadyPrintedSpace = false;
                    atLeastOneChar = true;
                    buffer += c;
            }
        }
        if (!buffer.empty()) {
            message += code[buffer];
        }
        std::cout << "Message #" << caseNumber << std::endl;
        std::cout << message << std::endl;
        if (t) std::cout << std::endl;
        caseNumber++;
    }
    return 0;
}