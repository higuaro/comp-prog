/*
ID: henry.e1
LANG: C++
TASK: calfflac
*/

#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

void checkPalFrom(const string& msg, int li, int ri, int& palLen, int& minIndex, int& maxIndex)
{
	int len = msg.size();
	char l, r;
	while(li >= 0 && ri < len) {
		while(li >= 0  && !isalpha((l = msg[li]))) li--;
		while(ri < len && !isalpha((r = msg[ri]))) ri++;
		if(li < 0 || ri >= len || toupper(l) != toupper(r)) break;
		palLen += 2;
		minIndex = li;
		maxIndex = ri;
		li--; ri++;
	}
}

int main()
{
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	
	string msg("");
	string line("");

	int palLen, minIndex, maxIndex;
	palLen = minIndex = maxIndex = 0;
	while(getline(fin, line))
		msg += line + '\n';

	int len = msg.size() - 1;
	for(int i = 1; i < len; i++) {
		if(!isalpha(msg[i])) continue;
		int pL, minI, maxI;

		for(int k = 0; k < 2; k++) {
			pL = k;
			minI = maxI = 0;		
			checkPalFrom(msg, i - 1, i + k, pL, minI, maxI);
			if(pL > palLen) { 
				minIndex = minI; 
				maxIndex = maxI;
				palLen = pL;
			}
		}
	}
	fout << palLen << endl;
	for(int i = minIndex; i < maxIndex + 1; i++)
		fout << msg[i];
	fout << endl;
	return 0;
}

