#include <iostream>

using namespace std;

int isqr(int n, int s) { 
	if (n <= 1) return n;
	int next = n / 2;
	int current;
	do { 
		current = next;
		next = (next + (n / next)) / 2;
	} while(next < current);
	return current;
}

int main()  { 
	for(int i = 1; i < 20; i++) 
		cout << i << " " << isqr(i, 2) << endl;
}
