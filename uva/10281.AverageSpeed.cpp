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

size_t toSeconds(const std::string& time) {
    std::istringstream iss(time);
    std::string value;
    std::getline(iss, value, ':');
    size_t seconds = std::stoi(value) * 3600;
    std::getline(iss, value, ':');
    seconds += std::stoi(value) * 60;
    std::getline(iss, value);
    return seconds + std::stoi(value);
}

std::string toTime(size_t seconds) {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << (seconds / 3600);
    oss << ':' << std::setfill('0') << std::setw(2) << ((seconds % 3600) / 60);
    oss << ':' << std::setfill('0') << std::setw(2) << (seconds % 60);    
    return oss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    std::ifstream fis("AverageSpeed.in");
    std::cin.rdbuf(fis.rdbuf());
#endif   
    std::string line;
    double currentSpeed = 0.0;
    size_t lastTime = 0;
    size_t totalTimeTraveled = 0;
    double distance = 0.0; 
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string time; 
        std::string speed;
        iss >> time >> speed;
        size_t seconds = toSeconds(time);
        size_t delta = seconds - lastTime;
        lastTime = seconds;
        totalTimeTraveled += delta;
        distance += static_cast<double>(delta) * currentSpeed;
        
        if (!speed.empty()) {
            currentSpeed = std::stod(speed) / 3600.00;
        } else {
            std::cout << toTime(totalTimeTraveled) << ' ' << std::fixed << std::setprecision(2) << distance << " km" << std::endl;
        }
    }
    return 0;
}