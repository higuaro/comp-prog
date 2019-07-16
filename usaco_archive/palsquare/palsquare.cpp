/*
ID: henry.e1
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <climits>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string numberToString(int number, int base = 10) 
{
	assert(base > 1);
	char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
					  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'O' };
	string res("");
	int d;
	while(number >= base) {
		d = number % base;
		res = digits[d] + res;
		number /= base;
	}
	d = number % base;
//	res = digits[d] + res;
	res = digits[number] + res;
	return res;
}

bool isPal(const string& line)
{
	int size = line.size();
	int len = size >> 1;
	for(int i = 0; i < len; i++) 
		if(line[i] != line[size - 1 - i]) 
			return false;
	return true;
}

int main() 
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	
//cout << "(5, 2) = " << numberToString(65535, 16) << endl; 
	
	int base;
	string number;
	string root;
	while(fin >> base) { 
		int square;
		for(int i = 1; i <= 300; i++) { 
			square = i * i;
			number = numberToString(square, base);
			if(isPal(number)) { 
				root = numberToString(i, base);
				fout << root << " " << number << endl; 
			}
		}
	}
	return 0;
}

