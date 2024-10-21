#include <iostream>

int main() {
    int alg[11] {0};
    int baj[11] {0};

    int temp;
    int resA = 0, resB = 0;

    for(int i = 0; i < 18; ++i) {
        std::cin >> temp;
        resA += temp;
        ++alg[temp];
    }

    for(int i = 0; i < 18; ++i) {
        std::cin >> temp;
        resB += temp;
        ++baj[temp];
    }

    if(resA > resB) std::cout << "Algosia";
    else if(resA < resB) std::cout << "Bajtek";
    else {
        int i = 10;
        bool f = false;
        while(i >= 0 && !f) {
            if(alg[i] > baj[i]) {
                std::cout << "Algosia";
                f = true;
            }
            else if(alg[i] < baj[i]) {
                std::cout << "Bajtek";
                f = true;
            }
            --i;
        }
        if(!f) std::cout << "remis";
    }

    return 0;
}