#include <iostream>
#include <cmath>

int main() {
    int h, w;
    std::cin >> h >> w;

    int n;
    std::cin >> n;
    int sizes[30];

    for(int i = 0; i < n; ++i) {
        std::cin >> sizes[i];
    }

    int i = 0;
    long long width = w / sizes[i];
    long long height = h / sizes[i]; 

    long long count = width * height;

    ++i;
    while(i < n) {
        width = width / (sizes[i] / sizes[i - 1]);
        height = height / (sizes[i] / sizes[i - 1]);
        if(width > 0 && height > 0) {
            count = count - width * height * (sizes[i] / sizes[i - 1]) * (sizes[i] / sizes[i - 1]) + width * height;
            ++i;
        }
        else {
            break;
        }
    }

    if(h % sizes[0] == 0 && w % sizes[0] == 0) {
        std::cout << count;
    }
    else {
        std::cout << -1;
    }

    return 0;
}
