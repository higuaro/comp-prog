#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
const int MAX = 8;
float dist[MAX * 2][MAX * 2];

int main() {
    std::vector<std::pair<int, int>> points;

    int n; std::cin >> n;
    while (n--) {
        int x, y;
        std::cin >> x >> y;
        points.push_back(std::make_pair(x, y));
    }
    int n_points = points.size();
    for (int i = 0; i < n_points; i++) {
        for (int j = 0; j < n_points; j++) {
            if (i == j) continue;
            int dx = std::abs(p[i].first() - p[j].first());
            int dy = std::abs(p[i].second() - p[j].second());
            dist[i][j] = std::sqrtf(dx * dx + dy * dy);
        }
    }

    float min = std::numeric_limits<float>::max();
    const all_used_mask = (1 << n_points) - 1;
    
    for (int k = 0; k < n_points; k++) {
        int used = 0;
        for (int i = k; i < n_points && (used ^ all_used_mask); i++) {
            int used |= 1 << i;
            for (int j = 0; j < n_points; j++) {
                if (used & (1 << j)) continue;
                
                used |= 1 << j;
            }
        }
    }
    
    return 0;
}
