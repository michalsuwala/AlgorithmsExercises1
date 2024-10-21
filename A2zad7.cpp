#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> planets(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> planets[i];
    }

    int p;
    std::cin >> p;

    std::vector<int> pattern(p);
    long patternValue = 0;
    long planetValue = 0;
    for (int i = 0; i < p; ++i) {
        std::cin >> pattern[i];
        patternValue = (pattern[i] + 101 * patternValue) % 7;
        planetValue = (planets[i] + 101 * planetValue) % 7;
    }

    int h = 1;
    for (int i = 0; i < p - 1; ++i) {
        h = (h * 101) % 7;
    }   
    
    int first = -1, second = 0;
    for (int i = p; i <= n; ++i) {
        if (patternValue == planetValue) {
            bool f = true;
            for (int j = i - p, k = 0; j < i; ++j, ++k) {
                if(planets[j] != pattern[k]) {
                    f = false;
                    break;
                }
            }
            if (f && first < 0) {
                first = i - p;
                
            }
            else if (f) {
                second = i - p;
                break;
            }
        }

        planetValue = (101 * (planetValue - planets[i - p] * h) + planets[i]) % 7;
        if(planetValue < 0) planetValue += 7;
    }

    //std::cout << first << ' ' << second;

    int temp = 0;
    if (second) {
        while (second < n) {
            temp = first + second;
            first = second;
            second = temp;
        }
    }

    std::cout << second - n;

    return 0;
}