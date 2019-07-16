/*
ID: henry.e1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstddef>
#include <vector>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int whiteToColor(int posI, string& cad)
{
	int size = cad.size();
	char col1 , col2;
	col2 = col1 = 'w';
	int pos1, pos2;
	for(int i = posI - 1; (i < 0 ? size + i: i) != posI; i--) {
		int j = i < 0 ? size + i : i;
		if(cad[j] != 'w') {
			col1 = cad[j];
			pos1 = j;
			break;
		}
	}
	for(int i = posI + 1; (i % size) != posI; i++) {
		if(cad[i % size] != 'w') {
			col2 = cad[i % size];
			pos2 = i % size;
			break;
		}
	}

	if(col2 == col1 && col1 != 'w') {
		for(int i = pos1; (i % size) != posI; i++)
			cad[i % size] = col1;			
		for(int i = pos2; (i < 0 ? size + i : i) != posI; i--)
			cad[i < 0 ? size + i : i] = col2;
		cad[posI] = col1;
	}

	return (col1 == col2 && col2 == 'w');
}

int totalBeads(int posI, const string& cad)
{
	string marked(cad);

	int total = 1;
	int size = cad.size();
	char col1, col2;
	col1 = cad[posI];
	col2 = cad[(posI + 1) % size];
	for(int i = posI - 1; (i < 0 ? size + i : i) != posI; i--) {
		int j = i < 0 ? size + i : i;
		if(marked[j] == 'x') continue;
		if(cad[j] != 'w') 
			if(col1 == 'w') 
				col1 = cad[j];
			else if(cad[j] != col1)
				break;
		marked[j] = 'x';
		total++;
	}
	for(int i = posI + 1; (i % size) != posI; i++) {
		int j = i % size;
		if(marked[j] == 'x') continue;
		if(cad[j] != 'w') { 
			if(col2 == 'w') {
				col2 = cad[j];
			} else if(cad[j] != col2) {
				break;
			}
		}
		marked[j] = 'x';
		total++;
	}
	return total;
}

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int beadCount;
	string necklace;
	vector<int> points;
	while(fin >> beadCount) {
		fin >> necklace;
		int size = necklace.size();

		//cout << necklace << endl;
		for(int i = 0; i < size; i++) {
			if(necklace[i] == 'w')
				whiteToColor(i, necklace);
		}
		//cout << necklace << endl;

		char currentBead = necklace[0];
		for(int i = 1; i < size; i++) {	
			char bead = necklace[i % size];
			if(currentBead == 'w') { 
				currentBead = bead;
				continue;
			}
			if(currentBead != bead)
				points.push_back(i - 1);
			currentBead = bead;
		}
		if(necklace[size - 1] != necklace[0]) 
			points.push_back(size - 1);

		int max = INT_MIN;
		int totalPoints = points.size();
		for(int i = 0; i < totalPoints; i++) {
			int t = totalBeads(points[i], necklace);
			if(t > max) 
				max = t;
		}
		fout << (totalPoints == 0 ? necklace.size() : max) << endl;
		points.clear();
	}

	return 0;
}
