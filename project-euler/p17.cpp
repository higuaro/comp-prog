#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    size_t units[] = { 0, strlen("one"), 
    strlen("two"), strlen("three"), strlen("four"), strlen("five"), 
    strlen("six"), strlen("seven"), strlen("eight"), strlen("nine"), strlen("ten"), 
    strlen("eleven"), strlen("twelve"), 
    strlen("thirteen"), strlen("fourteen"), strlen("fifteen"), strlen("sixteen"), strlen("seventeen"), 
    strlen("eighteen"), strlen("nineteen")
    };
    size_t decenes[] = { 0, 0, strlen("twenty"), strlen("thirty"), strlen("forty"), strlen("fifty"), 
    strlen("sixty"), strlen("seventy"), strlen("eighty"), strlen("ninety") };
    
    size_t hundreds = strlen("hundred");
    size_t thousand = strlen("thousand");
    size_t _and = strlen("and");
    
    const size_t LIMIT = 1000;
    size_t totalLetters = 0;
    for (size_t n = 1; n <= LIMIT; n++) { 
        if (n < 20) { 
            totalLetters += units[n];
        } else { 
            if (n == 1000) { 
                totalLetters += (units[1] + thousand); 
            } else { 
                int u = n % 10;
                int d = (n / 10) % 10;
                int c = (n / 100);
// cout << c << ',' << d << ',' << u << endl;
                if (c) totalLetters += (units[c] + hundreds + (d || u ? _and : 0));
                if (d * 10 + u < 20) {
                    totalLetters += units[d * 10 + u];
                } else { 
                    if (d) totalLetters += decenes[d];
                    if (u) totalLetters += (units[u]);                
                }
            }            
        }
    }
    cout << totalLetters << endl;
    
    return 0;
}

