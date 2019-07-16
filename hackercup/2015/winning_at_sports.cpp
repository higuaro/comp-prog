#include <fstream>
#include <iostream>
#include <cstring>
#include <bitset>
#include <list>
#include <vector>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <map>
#include <ctime>

typedef unsigned long long ull;

template<typename Type> 
std::vector< std::vector<Type> > createTable(const size_t numRows, const size_t numCols, Type defaultValue = Type()) { 
    std::vector< std::vector<Type> > table;
    for (size_t i = 0; i < numRows; ++i) { 
        table.push_back(std::vector<Type>(numCols, defaultValue));
    }
    return table;
}

int main(int argc, char* argv[]) {
   const size_t N = 2000;
   std::vector< std::vector<ull> > stressfree = createTable<ull>(N, N, 0);
   std::vector< std::vector<ull> > stressful = createTable<ull>(N, N, 0);   
   // unsigned long stressfree[N][N];
   // unsigned long stressful[N][N];

   const unsigned long MOD = 1000000007L;
   
   // Init
   for (size_t i = 0; i < N; i++) {
      stressfree[i][0] = 1;
      stressfree[i][1] = i - 1;
   }
   
   for (size_t i = 0; i < N; i++) {
      stressful[i][0] = 1;
      stressful[i][1] = 1;
   }

   // Calculate
   for (size_t j = 2; j < N; j++)    
      for (size_t i = j + 1; i < N; i++)
         stressfree[i][j] = ( (stressfree[i - 1][j] % MOD) + (stressfree[i][j - 1] % MOD) ) % MOD; 

   for (size_t j = 2; j < N; j++)   
      for (size_t i = j + 1; i < N; i++) 
         stressful[i][j] = ( (stressful[i][j - 1] % MOD) + (stressful[i - 1][j - 1] % MOD) ) % MOD; 

   std::ifstream fis("winning_at_sports.txt");
   // std::ofstream fos("winning_at_sports.out");
   // std::cout.rdbuf(fos.rdbuf());
   
   int t; fis >> t; fis.ignore(256, '\n');
   int cases = 1;
   while (t--) {
      int a, b;
      fis >> a >> b; fis.ignore(256, '\n');
      b *= -1;
      std::cout << "Case #" << cases << ": " << stressfree[a][b] << ' ' << stressful[a][b] << std::endl;
      cases++;
   }
   
   return 0;
}
