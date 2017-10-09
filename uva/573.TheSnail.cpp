#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

int simulateSnail(int h, int u, int d, int f) {
   int day = 1;
   const double H = static_cast<double>(h); 
   double currentHeight = 0.0;
   double scaleFactor = static_cast<double>(u);
   double slideFactor = static_cast<double>(d);
   double fatigue = scaleFactor * (f / 100.0);
   while (currentHeight <= H || currentHeight > 0.0) {
      currentHeight += scaleFactor;
      if (currentHeight > H) break;
      currentHeight -= slideFactor;
      if (currentHeight < 0.0) break;      
      scaleFactor = std::max(scaleFactor - fatigue, 0.0);      
      day++;
   }
   return currentHeight < 0.0 ? -day : day;
}

int main() {
#ifndef ONLINE_JUDGE
   std::ifstream fis("TheSnail.in");
   std::cin.rdbuf(fis.rdbuf());     
#endif
   int h, u, d, f;   

   while (std::cin >> h >> u >> d >> f && h) {
      int day = simulateSnail(h, u, d, f);
      if (day < 0) { 
          std::cout << "failure on day " << (-day) << std::endl; 
      } else {
          std::cout << "success on day " << day << std::endl;          
      }
   }

   return 0;
}
