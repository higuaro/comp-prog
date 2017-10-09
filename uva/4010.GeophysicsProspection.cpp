#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
struct point { 
	int z, i, j; 
	point(int z, int i, int j) : z(z), i(i), j(j) 
	{}
};

int bfs(char data[50][50][50], int z, int i, int j, char mineral, int maxZ, int maxI, int maxJ)
{
	char posi[] = { 0, 0,  0, 0, -1, 1};
	char posj[] = { 0, 0, -1, 1,  0, 0};
	char posz[] = {-1, 1,  0, 0,  0, 0};

	queue<point> q;
	point p(z, i, j); 
	q.push(p);
	data[z][i][j] = '*';
	int group = 1;

	while(!q.empty()) {
		point sample = q.back();
		q.pop();
		for(int count = 0; count < 6; count++) {
			int zz = sample.z + posz[count];
			int ii = sample.i + posi[count];
			int jj = sample.j + posj[count];
			if(zz >= 0 && zz < maxZ && ii >= 0 && ii < maxI && jj >= 0 && jj < maxJ) {
				if(data[zz][ii][jj] == mineral) {
					q.push(point(zz, ii, jj));
					data[zz][ii][jj] = '*';
					group++;
				}
			}
		}
	}
	return group;
}

int main()
{
	char data[50][50][50];
	int maxP, maxK, maxM;
	vector<int> groups[4];
	ifstream fin("geophysics.in");
	ofstream fout("geophysics.out");
	int cases = 0;
	while(fin >> maxP >> maxK >> maxM) { 
		for(int z = 0; z < 4; z++) 	groups[z].clear(); 

		string line;
		for(int m = 0; m < maxM; m++) { 
			for(int p = 0; p < maxP; p++) {
				fin >> line;
				for(int k = 0; k < maxK; k++) {
					data[m][p][k] = line[k];
				}
			}
		}

		for(int m = 0; m < maxM; m++) { 
			for(int p = 0; p < maxP; p++) {
				for(int k = 0; k < maxK; k++) {
					char mat = data[m][p][k];
					if(mat != '*')
							groups[mat - 'a'].push_back(bfs(data, m, p, k, mat, maxM, maxP, maxK));
				}
			}
		}

		fout << "Case " << (cases + 1) << ":" << endl;
		char material[] = {'a', 'b', 'c', 'd'};
		for(int i = 0; i < 4; i++) {
			fout << material[i] << ' ';

			if(groups[i].size()) {
				sort(groups[i].begin(), groups[i].end(), greater<int>());
				int size = groups[i].size();
				for(int k = 0; k < size; k++) {
					fout << groups[i].at(k);
					if(k < (size - 1)) 
						fout << ' ';
				}
			} else {
				fout << '0';
			}
			fout << endl;
		}
		fout << endl;
		cases++;
	}
	return 0;	
}
