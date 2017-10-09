#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <limits>
#include <iomanip>
#include <cstdint>
#include <map>
int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("10420.ListOfConquers.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    int n;
    std::cin >> n; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<std::string> cuntries;
    std::map< std::string, std::map<std::string, bool> > conquers;
    while (n--) {
        std::string country, name, line, tmp;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> country;
        if (!conquers.count(country)) cuntries.push_back(country);
        
        while (iss >> tmp) name += tmp + " ";
        conquers[country][name] = true;
    }
    std::sort(cuntries.begin(), cuntries.end());
    for (auto country : cuntries) {
        std::cout << country << ' ' << conquers[country].size() << std::endl;
    }    
    return 0;
}