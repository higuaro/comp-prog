#include <fstream>
#include <iostream>

using namespace std;

int getDayOfWeek(int d, int m, int y) 
{
	int days[] = {0, 31, days[1] + 28, days[2] + 31, days[3] + 30, days[4] + 31, days[5] + 30, days[6] + 31, days[7] + 31, days[8] + 30, days[9] + 31, days[10] + 30, days[11] + 31};
	int offset = m > 2 && (!(y % 400) || ((y % 100) && !(y % 4))) ? 1 : 0;
	return y -= 1901, ((y + 1) * 365 + (y / 4) - (y / 100) + ((y + 1900) / 400) - 4 + days[m - 1] + offset + d - 1) % 7;
}

int main()
{
/*
    int d[] = {0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < numYears; i++)
        for(int j = 1; j <= 12; j++)
            d[getDayOfWeek(13, j, 1900 + i)]++;
  */  
    size_t count = 0;
    for (int y = 1901; y <= 2000; y++)
        for (int m = 1; m <= 12; m++)
            if (getDayOfWeek(1, m, y) == 6)
                count++; 
    cout << count << endl;    
}
