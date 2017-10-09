#include <cstdlib>
#include <fstream>
#include <iostream>
#include <functional>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void readNumberTestCases(int& numTestCases) {
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> numTestCases;
}

bool isEmtpy(const std::string& str) {
    if (!str.empty()) { 
        std::string::const_iterator it = str.begin();
        do {
            if (it == str.end()) return true;
        } while (*it >= 0 && *it <= 0x7f && std::isspace(*(it++)));
        return false;
    } 
    return true;
}

struct Score { 
    int index, time, probs, problems[9], penalties[9];
    Score(int index = 0) : index(index), time(0), probs(0) {
        memset(penalties, 0, 9 * sizeof(int));
        memset(problems, 0, 9 * sizeof(int));
    }
    long totalTime() const { 
        int totalTime = time; 
        for (int i = 0; i < 9; i++) totalTime += problems[i] * penalties[i] * 20; 
        return totalTime; 
    }
    long getScore() const {
        return (probs * 10000000) + 1000000 - totalTime() * 100 - index;
    }
    bool operator<(const Score& score) { return getScore() > score.getScore(); }
};

bool sortFunction(std::pair<int, Score> first, std::pair<int, Score> second) { 
    return first.second < second.second;
}

int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
    ifstream fis("ContestScoreboard.in");
    cin.rdbuf(fis.rdbuf());
#endif    
    int testCases = 0;
    readNumberTestCases(testCases);
    string line;
    // Discard first empty line after num cases 
    getline(cin, line);
    
    while (testCases--) { 
        map<int, Score> teams;
        while (getline(cin, line) && !isEmtpy(line)) { 
            istringstream iss(line);
            int numTeam, problem, time;
            char status;
            iss >> numTeam >> problem >> time >> status;

            if (!teams.count(numTeam)) teams[numTeam] = Score(numTeam);            

            // Ignore already solved problems
            if (teams[numTeam].problems[problem]) continue;

            if (status == 'I') teams[numTeam].penalties[problem]++;
            if (status == 'C') {
                teams[numTeam].time += time;
                teams[numTeam].probs++;
                teams[numTeam].problems[problem] = 1;
            }
        } 

        std::vector< std::pair<int, Score> > results(teams.begin(), teams.end());            
        std::sort(results.begin(), results.end(), &sortFunction);

        std::vector< std::pair<int, Score> >::iterator ite;
        for (ite = results.begin(); ite != results.end(); ++ite) { 
            Score s(ite->second);
            cout << s.index << " " << s.probs << " " <<  s.totalTime() << endl;
        }
        if (testCases) cout << endl;
    }
    return 0;
}