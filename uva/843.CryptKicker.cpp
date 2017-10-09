#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cstring>

using namespace std;

void resetSolutionString(string& sol, const string& originalLine) {
    size_t len = originalLine.size();
    for (size_t i = 0; i < len; ++i) if (originalLine[i] != ' ') sol[i] = '*';
}

string getPattern(const string& word) { 
    size_t len = word.size();
    char abc[27]; memset(abc, 0, 27 * sizeof(char));
    size_t count = 0; string pattern;
    for (size_t charIndex = 0, i = 0; charIndex = word[i] - 'a', i < len; i++) {
        if (!abc[charIndex]) {
            count++;
            abc[charIndex] = count;
        }
        pattern += abc[charIndex] + '0' - 1;
    }
    return pattern;
}

bool isSolved(const string& sol) { 
    size_t size = sol.size();
    for (size_t i = 0; i < size; i++) if (sol[i] == '*') return false;
    return true;
}

bool applyWord(const string& applyWord, const string& line, string& sol, const size_t solStringIndex, string& usedChars) {
    // Apply word
    size_t applyWordLen = applyWord.size();
    size_t solLen = sol.size();

    for (size_t i = 0; i < applyWordLen; i++) { 
        char toReplace = line[solStringIndex + i];
        char replacement = applyWord[i];
        // Check if letter has been used 
        char usedChar = usedChars[replacement - 'a'];
        if (usedChar != ' ') {
            if (usedChar != toReplace) {
                return false;
            } else {
                continue;
            }
        }
        for (size_t j = solStringIndex; j < solLen; j++) {
            if (line[j] == toReplace) {
                if (sol[j] != replacement && sol[j] != '*') {
                    // wrong word!!
                    return false;
                } 
                sol[j] = replacement;
                usedChars[replacement - 'a'] = toReplace;
            }
        }
    }
    return true;
}

size_t advanceSolIndex(const string& sol, size_t currentIndex, size_t appliedWordSize) {
    size_t solLen = sol.size();
    size_t i = currentIndex + appliedWordSize;
    for (; i < solLen; i++) if (sol[i] != ' ') break;
    return i;
}

void decrypt(string& sol, string& usedChars, const vector<string>& words, const size_t index, const size_t solIndex, const string& line, const map<string, string> dics[]) {
    if (index >= words.size()) {
        return;
    }

    string word = words[index];
    string pattern = getPattern(word);
    size_t wordLen = word.size();
    map<string, string>::const_iterator ite = dics[wordLen - 1].begin();
    map<string, string>::const_iterator end = dics[wordLen - 1].end();
    for (; ite != end; ++ite) {
        if (ite->second == pattern) { 
            string solCopy(sol);
            string usedCharsCopy(usedChars);
            if (applyWord(ite->first, line, sol, solIndex, usedChars)) {
                if (isSolved(sol)) {
                    return;
                }
                
                decrypt(sol, usedChars, words, index + 1, advanceSolIndex(sol, solIndex, ite->first.size()), line, dics);
                if (isSolved(sol)) {
                    return;
                } else {
                    sol = solCopy;
                    usedChars = usedCharsCopy;
                }
            } else {
                sol = solCopy;
                usedChars = usedCharsCopy;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    ifstream fis("CryptKicker.in");
    cin.rdbuf(fis.rdbuf());
#endif
    size_t numWords;
    cin >> numWords;
    map<string, string> dics[17];
    for (size_t i = 0; i < numWords; i++) {
        string word;
        cin >> word;
        dics[word.size() - 1][word] = getPattern(word);
    }
    
    string line;
    while ( getline(cin, line) ) {
        // Get the line's words
        istringstream iss(line);
        vector<string> words;
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter< vector<string> >(words));
        if (!words.size()) continue;

        string sol(line);
        resetSolutionString(sol, line);
        
        string usedChars(27, ' ');
        decrypt(sol, usedChars, words, 0, advanceSolIndex(sol, 0, 0), line, dics);
        if (isSolved(sol)) {
            cout << sol << endl;
        } else {
            resetSolutionString(sol, line);
            cout << sol << endl;
        }
    }
    
    return 0;
}
