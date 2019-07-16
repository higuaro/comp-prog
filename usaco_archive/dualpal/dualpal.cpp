/*
ID: henry.e1
LANG: C++
TASK: dualpal
*/

#include <cassert>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

string getNumberString(int number, int base = 10) 
{
	const char* digits = "0123456789ABCDEFGHIJ";
	string res;
	while(number >= base) {
		res = digits[number % base] + res;
		number /= base;
	}
	res = digits[number] + res;
	return res;	
}

bool isPal(const string& str) 
{
	int size = str.size();
	int len = size >> 1;
	int i = 0; 
	while(i < len)
		if(str[i] != str[size - 1 - i++]) return false;
	return true;
}

int main()
{ 
	ifstream fis("dualpal.in");
	ofstream fout("dualpal.out");
	
	int S, N;
	while(fis >> N >> S) {
		for(int i = 0, k = S + 1; i < N; k++) { 
			int numPals = 0;
			for(int b = 2; b <= 10; b++) {
				string number = getNumberString(k, b);
				if(isPal(number)) numPals++;
			}
			if(numPals >= 2) { 
				fout << k << endl;
				i++;
			}
		}
	}
	return 0;
}
