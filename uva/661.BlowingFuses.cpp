#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

int simulate(std::istream& cin, int numDevices, int states, int maxCapacity) {
   std::vector<int> capacities(numDevices, 0);
   std::vector<int> devices(numDevices, 0);   

   for (int i = 0; i < numDevices; i++) {
      cin >> capacities[i];
      cin.ignore(256, '\n');
   }   

   int maxFound = 0;   
   int currentCapacity = 0;
   for (int i = 0; i < states; i++) {
      int device; 
      cin >> device;
      
      if (maxFound >= 0) {
         int deviceIndex = device - 1;
         devices[deviceIndex] = !devices[deviceIndex];
         currentCapacity += (devices[deviceIndex] ? 1 : -1) * capacities[deviceIndex];
         maxFound = std::max(maxFound, currentCapacity);
         if (currentCapacity > maxCapacity) {
            maxFound = -1;
         }
      }
   }
   return maxFound;
}

void printSolution(int seq, int amperes) {
   /*
   if (seq > 1) { 
      std::cout << std::endl;
   }
   */
   std::cout << "Sequence " << seq << std::endl;
   if (amperes < 0) {
      std::cout << "Fuse was blown." << std::endl << std::endl;
   } else {
      std::cout << "Fuse was not blown." << std::endl;   
      std::cout << "Maximal power consumption was " << amperes << " amperes." << std::endl << std::endl;
   }
}

int main() {
#ifndef ONLINE_JUDGE
   std::ifstream fis("BlowingFuses.in");
   std::cin.rdbuf(fis.rdbuf());
#endif

   int sequences = 1;
   int n, m, c;
   while (std::cin >> n >> m >> c && (n || m || c)) {
      int amperes = simulate(std::cin, n, m, c);
      printSolution(sequences++, amperes);
   }
   return 0;
}
