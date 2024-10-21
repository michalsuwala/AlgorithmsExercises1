#include <iostream>
#include <vector>

int janosik(int n, std::vector<int>& chests) {
    if (chests[n] != -1) return chests[n];

    int rest = janosik(n / 2, chests) * 2;

    if (n % 2) {
        chests[n] = 1 + rest;
        return 1 + rest;
    }

    chests[n] = rest;
    return rest;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> chests;
    for (int i = 0; i <= n; ++i) {
        chests.push_back(-1);
    }
    chests[1] = 0;

    long long res = 0;
    for (int i = 2; i <= n; ++i) {
        res += janosik(i, chests);
    }

    std::cout << res;

    return 0;
}

//too much memory used