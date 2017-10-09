#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>

int main() {
    for (size_t a = 10; a < 99; a++) { 
        for (size_t b = a + 1; b <= 99; b++) { 
            size_t a1 = a / 10;
            size_t a2 = a % 10;

            size_t b1 = b / 10;
            size_t b2 = b % 10;
            
            bool case1 = (b2 == a1);
            bool case2 = (b1 == a2);
            
            double ab = static_cast<double>(a) / static_cast<double>(b);            
            double c;
            
            if (case1) c = static_cast<double>(a2) / static_cast<double>(b1);
            if (case2) c = static_cast<double>(a1) / static_cast<double>(b2);
            
            if ((case1 || case2) && std::abs(ab - c) <= std::numeric_limits<double>::epsilon()) { 
                std::cout << a << "/" << b << std::endl; 
            }
        }
    }
    
    // Solve with wxmaxima the following expression: 
    //   16/64*19/95*26/65*49/98;
    
    return 0;
}
