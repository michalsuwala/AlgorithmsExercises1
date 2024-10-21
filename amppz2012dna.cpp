#include <iostream>

int main () {
    int n;
    std::cin >> n;

    int count[4] = {0};
    for (int i = 0; i < n; ++i) {
        char temp;
        std::cin >> temp;

        if (temp == 'A') ++count[0];
        else if (temp == 'C') ++count[1];
        else if (temp == 'G') ++count[2];
        else ++count[3];
    }

    int min = 10001;
    char minChar;
    for (int i = 0; i < 4; ++i) {
        if (count[i] < min) {
            min = count[i];
            if (i == 0) minChar = 'A';
            else if (i == 1) minChar = 'C';
            else if (i == 2) minChar = 'G';
            else minChar = 'T';
        }
    }

    std::cout << min << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << minChar;
    }

    return 0;
}