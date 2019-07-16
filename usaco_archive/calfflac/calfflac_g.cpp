/*

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
//cout << "l = " << l << ", r = " << r << endl;
//int dummy;
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
		int palSize = 0;
		if(!isalpha(msg[i])) continue;
		// check pal from this char like it was the center of the pal
		int pL, minI, maxI;

//int dummy;
		pL = 1;
		minI = maxI = 0;		
//cout << "1. from = " << i - 1 << " to " << i + 1 << endl;		
		checkPalFrom(msg, i - 1, i + 1, pL, minI, maxI);
		if(pL > palLen) { 
			minIndex = minI; 
			maxIndex = maxI;
			palLen = pL;
//cout << "pal = " << pL << ", minI = " << minI << ", maxI = " << maxI << endl;			
		}
		cout << endl;
				
		pL = 0;
		minI = maxI = 0;
//cout << "2. from = " << i - 1 << " to " << i << endl;
		checkPalFrom(msg, i - 1, i, pL, minI, maxI);
		if(pL > palLen) { 
			minIndex = minI; 
			maxIndex = maxI;
			palLen = pL;
//cout << "pal = " << pL << ", minI = " << minI << ", maxI = " << maxI << endl;			
		}
		cout << endl;
	}
	cout << palLen << endl;
	for(int i = minIndex; i < maxIndex + 1; i++)
		cout << msg[i];
cout << endl;
	return 0;
}

