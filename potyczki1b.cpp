#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int count[n] {0};
    int temp;
    
    for(int i = 0; i < n; ++i) {
        std::cin >> temp;
        ++count[temp];
    }

    std::sort(count, count + n, std::greater<int>());

    int m = n;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        ++res;
        m = m - 2 * count[i] + 1;
        if(m <= 0) break;
    }

    std::cout << res;
    
    return 0;
} 