#include <iostream>
#include <string>
#include <map>

int main() {
    bool f = true;
    std::string line;
    int index;
    int data[26];

    for(int i = 0; i < 26; i++) {
        data[i] = 0;
    }

    while(f) {
        std::getline(std::cin, line);
        for(char c : line) {
            if(c == 94) {
                f = false;
                break;
            }

            if(c >= 65 && c <= 90) {
                index = c - 65;
                data[index] += 1;
            }
            else if(c >= 97 && c <= 122) {
                index = c - 97;
                data[index] += 1;
            }
        }
    }

    int max = 0;
    int indMax;

    int min = 2000000;
    int indMin;

    for(int i = 0; i < 26; i++) {
        if(data[i] < min && data[i] >= 1) {
            indMin = i;
            min = data[i];
        }

        if(data[i] > max && data[i] >= 1) {
            indMax = i;
            max = data[i];
        }
    }
    std::cout << char(indMax + 97) << ' ' << char(indMin + 97);
    return 0;
}