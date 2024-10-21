#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int count[n] {0};
    count[0] = n;

    std::unordered_map<int, int> cityCount;
    int temp;
    for(int i = 0; i < n; ++i) {
        std::cin >> temp;
        ++cityCount[temp];
    }

    for(auto city : cityCount) {
        for(int j = 1; j < n; ++j) {
            if(city.second >= j + 1) {
                count[j] += city.second - (city.second % (j + 1));
            }
         }
    }

    for(int i = 0; i < n; ++i) {
        std::cout << count[i] << ' ';
    }
    
    return 0;
}
