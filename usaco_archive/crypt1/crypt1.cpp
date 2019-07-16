/*
ID: henry.e1
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

typedef vector<int> vint;
typedef list<int> lint;

bool hasValidDigits(int number, const int totalDigits, const vint& validDigits)
{
	vint::const_iterator end = validDigits.end();
	for(int i = 0; i < totalDigits; i++) {
		int d = number % 10;
		number /= 10;
		vint::const_iterator ite = validDigits.begin();
		bool founded = false;
		for(; ite < end; ++ite)
			if(*ite == d) {
				founded = true;
				break; 
			}
		if(!founded) return false;
	}
	return true;
}

int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	
	int numElem;

	int pows[6];

	while(fin >> numElem) { 
		int totalSolutions = 0;
		vint validDigits;
		int temp = 1;
		for(int i = 0; i < numElem; i++) {
			int t;
			fin >> t;
			validDigits.push_back(t);
		}

		pows[0] = 1;
		for(int i = 1; i < 6; i++)
			pows[i] = numElem * pows[i - 1];
			
		for(int i = 0; i < pows[5]; i++) {
			int c[5];
			for(int j = 0; j < 5; j++) 
				c[j] = validDigits[(i / pows[j]) % numElem];
			
			int oper1 = c[4] * 100 + c[3] * 10 + c[2];
			int res1 = oper1 * c[0];
			int res2 = oper1 * c[1];
			if(res1 > 999) continue;
			if(res2 > 999) continue;
			if(!hasValidDigits(res1, 3, validDigits)) continue;
			if(!hasValidDigits(res2, 3, validDigits)) continue;
			res2 *= 10;
			res1 += res2;
			if(res1 > 9999) continue;
			if(!hasValidDigits(res1, 4, validDigits)) continue;
			
			totalSolutions++;
//cout << c[4] << c[3] << c[2] << endl;
//cout << ' ' << c[1] << c[0] << endl;
		}
		fout << totalSolutions << endl;
	}
	return 0;
}
