/*
ID: henry.e1
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");	
	const int MAX_SECONDS = 1000000;
	char timeline[MAX_SECONDS];
	int N;
	while(fin >> N) {
		memset(timeline, 0, sizeof (char) * MAX_SECONDS);
		int minTime, maxTime;
		for(int i = 0; i < N; i++) { 
			fin >> minTime >> maxTime;
			for(int k = minTime; k < maxTime; k++) 
				timeline[k] = 1;
		}
		
		int count[] = {0, 0};
		int maxs[]  = {-1, -1};
		int current = 0;
		bool milked = false;
		for(int i = 0; i < MAX_SECONDS; i++) {
			if(timeline[i] != current) {
				milked = true;
				if(count[current] > maxs[current]) 
					maxs[current] = count[current];
				count[current] = 0;
				current = (!current) & 1;
			}
			if(current == 0 && !milked) continue;
			count[current]++;
		}

		fout << maxs[1] << " " << maxs[0] << endl;
	}

	return 0;
}


