#include <iostream>
#include <algorithm>

void calories(int* v, int target, int index, int size, int& res) {
    if(v[index] > target) {
        return;
    }
    else if(v[index] == target) {
        res++;
        return;
    }
    else {
        target -= v[index];
        for(int i = index + 1; i < size; i++) {
            calories(v, target, i, size, res);
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        
        int *products = new int[n + 1];
        products[0] = 0;
        for(int j = 0; j < n; j++) {
            std::cin >> products[j + 1];
        }

        std::sort(products + 1, products + n + 1, std::greater<>());
        
        int k;
        std::cin >> k;

        int res = 0;
        if(k > 0) {
            calories(products, k, 0, n + 1, res);
        }
        std::cout << res << "\n";
        delete[] products;
    }

    return 0;
}
