#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <map>
#include <functional>
#include <queue>
#include <cctype>
#include <locale>

using namespace std;

struct Node {
    string name;
    int erdosNumber;
    map<string, Node*> children;
    
    Node() : name(""), erdosNumber(-1) {}
    Node(const string& name) : name(name), erdosNumber(-1) {}
};

void calculateErdos(Node* rootNode, map<string, Node*>& authors, map<string, bool> importantAuthors) {
    queue<Node*> q;
    
    q.push(rootNode);
    map<string, bool> visited;
    
    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();
        
        if (visited.count(currentNode->name)) continue;
        visited[currentNode->name] = true;

        if (currentNode->erdosNumber < 0) continue;

        map<string, Node*>::iterator ite, end;
        end = currentNode->children.end();
        for (ite = currentNode->children.begin(); ite != end; ++ite) {
            if (!visited.count(ite->first)) {
                int newErdosNumber = currentNode->erdosNumber + 1;
                Node* child = ite->second;
                if (child->erdosNumber < 0) {
                    child->erdosNumber = newErdosNumber;
                } else {
                    if (child->erdosNumber > newErdosNumber)
                        child->erdosNumber = newErdosNumber;
                }
                q.push(child);
            }
        }
    }
}

vector<string> getAuthorsInPaper(const string& authorsLine) {
    size_t size = authorsLine.size();
    vector<string> authors;
    int commaCount = 0;
    string acum;
    for (size_t i = 0; i < size; i++) {
        char c = authorsLine[i];
        if (c == ',' || c == ':') commaCount++;
        if (commaCount == 2) {
            commaCount = 0;
            authors.push_back(acum);
            acum = "";
            i++;
            if (c == ':') break;
            continue;
        }
        acum += c;
    }
    return authors;
}

void printOutput(map<string, Node*>& authors, vector<string>& importantAuthorNames, int testCaseNumber) {
    cout << "Scenario " << (testCaseNumber + 1) << endl;
    size_t numAuthors = importantAuthorNames.size();
    for (size_t authorIndex = 0; authorIndex < numAuthors; authorIndex++) { 
        cout << importantAuthorNames[authorIndex];
        Node* node = authors[importantAuthorNames[authorIndex]];
        if (node == NULL || node->erdosNumber < 0)
            cout << " infinity" << endl;
        else
            cout << " " << node->erdosNumber << endl;
    }           
}

void cleanMemoryFromMap(map<string, Node*>& authors) {
    map<string, Node*>::iterator ite, end;
    ite = authors.begin();
    while (ite != authors.end()) {
        std::map<string, Node*>::iterator toErase = ite;
        ++ite;
        delete toErase->second;
        authors.erase(toErase);
    }    
}

void readTestCaseParameters(int& numPapers, int& numAuthors) {
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> numPapers >> numAuthors;
}

void readNumberTestCases(int& numTestCases) {
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> numTestCases;
}

int main() {
#ifndef ONLINE_JUDGE
    ifstream fis("ErdosNumber.in");
    cin.rdbuf(fis.rdbuf());
#endif
    int numTestCases;
    readNumberTestCases(numTestCases);
    int currentTestCase = 0;
    
    while (numTestCases--) {
        map<string, Node*> authors;

        int numAuthors;
        int numPapers;
        readTestCaseParameters(numPapers, numAuthors);

        /////////////////////////////
        // READ AND PARSE THE PAPERS
        /////////////////////////////                
        for (int paperIndex = 0; paperIndex < numPapers; paperIndex++) {
            string paperLine;
            getline(cin, paperLine);
            vector<string> authorsInThisPaper = getAuthorsInPaper(paperLine);

            size_t numAuthorsInThisPaper = authorsInThisPaper.size();
            for (size_t i = 0; i < numAuthorsInThisPaper; i++)
                if (!authors.count(authorsInThisPaper[i]))
                    authors[authorsInThisPaper[i]] = new Node(authorsInThisPaper[i]);

            for (size_t i = 0; i < numAuthorsInThisPaper; i++) {
                for (size_t j = 0; j < numAuthorsInThisPaper; j++) {                        
                    if (i == j) continue;
                    string authorA = authorsInThisPaper[i];
                    string authorB = authorsInThisPaper[j];
                    authors[authorA]->children[authorB] = authors[authorB];
                }
            }
        }
        
        //////////////////////////
        // READ THE AUTHORS
        //////////////////////////
        map<string, bool> importantAuthors;
        vector<string> importantAuthorNames;
        for (int authorIndex = 0; authorIndex < numAuthors; authorIndex++) { 
            string authorName;
            getline(cin, authorName);
            importantAuthorNames.push_back(authorName);
            importantAuthors[authorName] = false;
        }
        
        /////////////////////////////////
        // CALCULATE ERDOS NUMBERS
        /////////////////////////////////
        if (!authors.count("Erdos, P.")) authors["Erdos, P."] = new Node("Erdos, P.");
        authors["Erdos, P."]->erdosNumber = 0;        
        calculateErdos(authors["Erdos, P."], authors, importantAuthors);

        /////////////////////////////////
        // PRINT OUTPUT
        /////////////////////////////////
        printOutput(authors, importantAuthorNames, currentTestCase);
                
        /////////////////////////////////
        // CLEAN MEMORY 
        /////////////////////////////////        
        cleanMemoryFromMap(authors);
        
        currentTestCase++;
    }
    return 0;
}