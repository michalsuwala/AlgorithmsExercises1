#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, s;
        std::cin >> n >> s;
        long long free = 0, daily = 0;
        int min = std::numeric_limits<int>::max();

        for (int j = 0; j < n; ++j) {
            int v, f;
            std::cin >> v >> f;
            free += v;
            daily += f;
            if (daily != 0 && free / daily < min) min = free / daily;
        }

        if (daily != 0) std::cout << std::min(min, s) << '\n';
        else std::cout << s << "\n";
    }


    return 0;
}