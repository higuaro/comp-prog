/*
ID: henry.e1
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
#include <list>

using namespace std;

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	bool stalls[210];
	int m, s, c;

	while(fin >> m >> s >> c) { 
        int first = INT_MAX;
        int last = INT_MIN;
		memset(stalls, false, sizeof(stalls));

		for(int i = 0; i < c; i++) { 
			int cell;
			fin >> cell;
			stalls[--cell] = true;
            if(cell > last) last = cell;
            if(cell < first) first = cell;
		}
//cout << "f = " << first << ", l = " << last << endl;
		list<int> segments;
		int len = 0;
		for(int i = 0; i < s; i++) {
            if(stalls[i] == false && i >= first && i <= last)
				len++;
			else {
				if(len) {
//cout << "pushing len = " << len << endl;
					segments.push_back(len);
					len = 0;
				}
			}
		}
		if(len) {
//cout << "pushing len = " << len << endl;
			segments.push_back(len);
			len = 0;
		}
		
		segments.sort(greater<int>());
		int total = 0;
		list<int>::iterator ite = segments.begin();
		list<int>::iterator end = segments.end();
//cout << "{"; 
        for(int i = 0, limit = m - 1; i < limit && ite != end; ++i, ++ite) {
//        	cout << *ite << ", ";
			total += *ite;
		}
//cout << "}" << endl;
		fout << last - first + 1 - total << endl;
	}

	return 0;
}	
