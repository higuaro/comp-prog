/*
ID: henry.e1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct trieNode
{
	const char car;
	list<trieNode*> alphabet;
	trieNode(const char car) : car(car) {}
	trieNode() : car(0) {}
};

struct trie
{
	trieNode root;

	trie() {}

	void load(const char* word)
	{
cout << "cargando palabra: " << word << endl;
		trieNode* current = &root;
		for(; *word; ++word) {
cout << "[ " << *word << "]";
			trieNode* node;
			if((node = findNodeInNodeAlphabet(current, *word)) == NULL) {
				trieNode* newNode = new trieNode(*word);
				current->alphabet.push_back(newNode);
				current = newNode;
cout << "new, ";
			} else {
				current = node;// current->alphabet[*word];
cout << ", ";
			}
		}
cout << endl;
	}

	trieNode* findNodeInNodeAlphabet(const trieNode* t, const char c)
	{
	 	list<trieNode*>::const_iterator ite = t->alphabet.begin();
	 	list<trieNode*>::const_iterator end = t->alphabet.end();
	 	for(; ite != end; ++ite) {
	 		if((*ite)->car == c)
	 			return *ite;
	 	}
	 	return NULL;
	}

	bool exist(const char* word)
	{
		trieNode* current = &root;
cout << "procesando palabra: ";
		for(; *word; ++word) {
cout << *word << ",";
			trieNode* node;
			node = findNodeInNodeAlphabet(current, *word);
			if(node == NULL) {
cout << "!! No esta en el dic" << endl;
				return false;
			}
			current = node;
		}
		cout << "la palabra completa esta en el dic" << endl;
		return true;
	}
};

int main()
{
    ifstream fin("namenum.in");
    ifstream dict("dict.txt");
    ofstream fout("namenum.out");

	trie tdic;

    const int MAX_WORD_SIZE = 13;
    char word[MAX_WORD_SIZE];
    while(dict >> word)
    	tdic.load(word);

    char table[][3] = { { 'A', 'B', 'C' },
                        { 'D', 'E', 'F' },
                        { 'G', 'H', 'I' },
                        { 'J', 'K', 'L' },
                        { 'M', 'N', 'O' },
                        { 'P', 'R', 'S' },
                        { 'T', 'U', 'V' },
                        { 'W', 'X', 'Y' } };

    char number[MAX_WORD_SIZE];
    int pows[MAX_WORD_SIZE];
    int pow = 1;
    pows[0] = 1;
    for(int i = 1; i < MAX_WORD_SIZE; i++) {
    	pow *= 3;
    	pows[i] = pow;
    }

    while(fin >> number) {
cout << number << endl;
        int len = strlen(number);
cout << "len = " << len << endl;
        int numPerm = pows[len];
        list<string> names;
        for(int i = 0; i < numPerm; i++) {
        	char perm[MAX_WORD_SIZE];
        	memset(perm, 0, MAX_WORD_SIZE);
        	for(int j = 0; j < len; j++) {
        	 	int digit = number[j] - '2';
	        	perm[j] = table[digit][(i / pows[j]) % 3];
        	}
        	perm[len] = 0;
//cout << "Probando permutacion: " << perm << endl;
			//string key(perm);
        	if(tdic.exist(perm)) {
cout << "En el dic!!" << endl;
	        	names.push_back(string(perm));
	        }
        }
        if(names.size()) {
		    names.sort();
		    list<string>::iterator ite = names.begin();
		    list<string>::iterator end = names.end();
		    for(; ite != end; ++ite)
		    	fout << (*ite) << endl;
        } else
        	fout << "NONE" << endl;
    }
	return 0;
}

